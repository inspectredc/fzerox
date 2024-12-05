# Adapted from AngheloAlf/drmario64
# SPDX-FileCopyrightText: © 2022-2024 AngheloAlf
# SPDX-License-Identifier: MIT

import sys
import argparse
import struct
import pathlib
import spimdisasm
import crunch64

# todo: generate this list from splat yaml
compressedEntries = [
    "segment_16C8A0",
    "segment_22B0A0",
    "segment_235130",
    "segment_239A80",
    "segment_23EC50",
    "segment_243D90",
    "segment_24A270",
    "segment_2507F0",
    "segment_255100",
    "segment_259600",
    "segment_25F360",
    "segment_266C20",
    "segment_26D780",
    "segment_2738A0",
]

VERBOSE = False

def addSymbolToRelocate(relsOffetsToApply: dict[int, tuple[str, spimdisasm.common.RelocType]], symName: str, rel: spimdisasm.elf32.Elf32RelEntry, segmentRomOffset: int, segmentVram: int):
    relVram = rel.offset

    rType = spimdisasm.common.Relocation.RelocType.fromValue(rel.rType)
    assert rType is not None, rel.rType

    relRomOffset = relVram - segmentVram + segmentRomOffset
    relsOffetsToApply[relRomOffset] = (symName, rType)

def align(value: int, n: int) -> int:
    return (((value) + ((n)-1)) & ~((n)-1))

def align8MB(value: int) -> int:
    return align(value, 0x100000)

def main(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('rom', help="uncompressed rom name")
    parser.add_argument('romc', help="compressed rom name")
    parser.add_argument('elf', help="elf file name")
    parser.add_argument('version', help="version")

    args = parser.parse_args()

    VERBOSE = args.verbose
    rom = pathlib.Path(args.rom)
    romc = pathlib.Path(args.romc)
    elf = pathlib.Path(args.elf)
    version = args.version

    segmentOffsets: dict[str, tuple[int, int]] = {}
    relsOffetsToApply: dict[int, tuple[str, spimdisasm.common.RelocType]] = {}
    romOffsetValues: dict[str, int] = {}

    # spimdisasm.common.GlobalConfig.VERBOSE = VERBOSE

    elfBytearray = spimdisasm.common.Utils.readFileAsBytearray(elf)
    assert len(elfBytearray) > 0, f"'{elf}' could not be opened"

    romBytearray = spimdisasm.common.Utils.readFileAsBytearray(rom)
    assert len(romBytearray) > 0, f"'{rom}' could not be opened"

    elfFile = spimdisasm.elf32.Elf32File(elfBytearray)

    romcBin = bytearray()

    offset = sizeWrote = 0

    for entry in elfFile.sectionHeaders.sections:
        sectionEntryName = elfFile.shstrtab[entry.name]

        if entry.type == spimdisasm.elf32.Elf32SectionHeaderType.REL.value:

            if sectionEntryName[1:] not in compressedEntries:
                sectionRels = spimdisasm.elf32.Elf32Rels(sectionEntryName, elfBytearray, entry.offset, entry.size)
                referencedSegment = sectionEntryName.replace(".rel.", ".")
                for rel in sectionRels.relocations:
                    sym = elfFile.symtab[rel.rSym]

                    symName = elfFile.strtab[sym.name]

                    symNameStripped = symName.replace("_VRAM_END", "")

                    if symName.endswith("_ROM_START") or symName.endswith("_ROM_END") or (symName.endswith("_VRAM_END") and symNameStripped in compressedEntries):
                        segmentData = segmentOffsets[referencedSegment]

                        addSymbolToRelocate(relsOffetsToApply, symName, rel, segmentData[0], segmentData[1])


        if entry.type != spimdisasm.elf32.Elf32SectionHeaderType.PROGBITS.value:
            if VERBOSE:
                print(f"Skiping segment '{sectionEntryName}' because it isn't PROGBITS")
            continue

        entryFlags, unknownFlags = spimdisasm.elf32.Elf32SectionHeaderFlag.parseFlags(entry.flags)
        if spimdisasm.elf32.Elf32SectionHeaderFlag.ALLOC not in entryFlags:
            if VERBOSE:
                print(f"Skiping segment '{sectionEntryName}' because it doesn't have the alloc flag")
            continue


        segmentOffsets[sectionEntryName] = (offset, entry.addr)
        romStartSymbol = f"{sectionEntryName[1:]}_ROM_START"
        romEndSymbol = f"{sectionEntryName[1:]}_ROM_END"
        vramEndSymbol = f"{sectionEntryName[1:]}_VRAM_END"

        offsetStart = sizeWrote

        if VERBOSE:
            print(f"Segment '{sectionEntryName}': offset=0x{offset:06X} entry.offset=0x{entry.offset:06X} entry.size=0x{entry.size:06X}")

        segmentBytearray = romBytearray[offset:offset+entry.size]

        assert len(segmentBytearray) == entry.size, f"'{sectionEntryName}': 0x{len(segmentBytearray):X} 0x{entry.size:X}"
        
        size = 0
        if sectionEntryName[1:] not in compressedEntries:
            # write as-is
            offsetEnd = entry.size + offsetStart
            if VERBOSE:
                print(f"Writing as is the segment '{sectionEntryName}' at rom offset 0x{offsetStart:06X} to 0x{offsetEnd:06X}.")
            romcBin.extend(segmentBytearray)
            size = entry.size
        else:
            compressedBytearray = bytearray(crunch64.mio0.compress(bytes(segmentBytearray)))

            # Align to a 0x10 boundary
            while len(compressedBytearray) % 0x10 != 0:
                compressedBytearray.append(0)

            offsetEnd = offsetStart + len(compressedBytearray)
            romcBin.extend(compressedBytearray)
            if VERBOSE:
                print(f"Writing compressed the segment '{sectionEntryName}' at rom offset 0x{offsetStart:06X} to 0x{offsetEnd:06X}.")

            size = len(compressedBytearray)

        sizeWrote += size

        romOffsetValues[romStartSymbol] = offsetStart
        romOffsetValues[romEndSymbol] = offsetEnd
        romOffsetValues[vramEndSymbol] = entry.addr + size
        
        offset += align(entry.size, 0x10)
        if VERBOSE:
            print()

    alignedSize = align8MB(sizeWrote)

    romcBin.extend(bytearray((alignedSize - sizeWrote) * [0xFF]))

    for relRomOffset, (symName, rType) in relsOffetsToApply.items():
        value = romOffsetValues[symName]
        hiValue = value >> 16
        loValue = value & 0xFFFF
        if loValue >= 0x8000:
            hiValue += 1

        if rType == spimdisasm.common.Relocation.RelocType.MIPS_HI16:
            struct.pack_into(f">H", romcBin, relRomOffset+2, hiValue)
        elif rType == spimdisasm.common.Relocation.RelocType.MIPS_LO16:
            struct.pack_into(f">H", romcBin, relRomOffset+2, loValue)
        elif rType == spimdisasm.common.Relocation.RelocType.MIPS_32:
            struct.pack_into(f">I", romcBin, relRomOffset, value)
        else:
            assert False, rType

    romc.write_bytes(romcBin)

    sys.exit()


if __name__ == "__main__":
    main(sys.argv[1:])
