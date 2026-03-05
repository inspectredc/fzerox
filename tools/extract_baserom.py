from leo64dd_python import leo64dd
from leo64dd_python import leo64ddfile

import argparse
import pathlib

RESERVED_BLOCK_COUNT = 24
LBA_MAX_COUNT = 4316
MAIN_BLOCK_START = 560
OVERLAY_BLOCKS = [ 598, 602, 613, 615, 617, 620, 622, 624, 635, 655, 656, 672, 677 ]
ASSET_BLOCKS = [ 684, 692 ]
COURSE_BLOCK_FIRST = 800
COURSE_BLOCK_FINAL = 811
COURSE_SIZE = 0x7E0
GHOST_BLOCK_FIRST = 834
GHOST_BLOCK_FINAL = 845
GHOST_SIZE = 0x3FC0
AUDIO_BLOCKS = [ 1000, 1002, 1004 ]
AUDIO_SIZES = [ 0x59F0, 0x3CF0, 0x1D9BDF0 ]

# ROM ADDRS: 0x0, 0xA2E70, 0xB0AB0, 0xDE7C0, 0xE6660, 0xEB850, 0xF5080, 0xFCC60, 0x1039E0, 0x132B30, 0x1872B0, 0x188850, 0x1CB1E0, 0x1E0B00, 0x1FB850(END)
MAIN_VRAM_JP = (0x806F2800, 0x80795670)
OVERLAY_VRAM_JP = [
    (0x80025C00, 0x80033840),
    (0x8003F2E0, 0x8006CFF0),
    (0x8006F1B0, 0x80077050),
    (0x80077080, 0x8007C270),
    (0x8007C2B0, 0x80085AE0),
    (0x800927C0, 0x8009A3A0),
    (0x8009B170, 0x800A1EF0),
    (0x800A20A0, 0x800D11F0),
    (0x800D6D90, 0x8012B510),
    (0x8012B520, 0x8012CAC0),
    (0x800D6D90, 0x80119720), # course edit
    (0x8012B520, 0x80140E40), # create machine
    (0x800D6D90, 0x800F1AE0),
]
ASSET_VRAM_JP = [
    (0x7000000, 0x7020920),
    (0x9000000, 0x9014E40),
]

def leo_decode(ba):
    out = bytearray()
    out.extend(ba)

    for i in range (0, 256):
        out[(i * 17) % 256] = ba[i]

    return out

def main(args):
    print()

    with open(args.file, "rb") as infile:
        disk_img = bytearray(infile.read())
    disk_obj = leo64ddfile.load_disk_file(disk_img)

    romBA = bytearray()
    rom = pathlib.Path("baserom." + args.version + "." + args.revision + ".z64dd")

    # Main Block

    nbytes = MAIN_VRAM_JP[1] - MAIN_VRAM_JP[0]
    disk_type = disk_obj.sys_data.disk_type
    lbaStart = MAIN_BLOCK_START + RESERVED_BLOCK_COUNT

    for i in range(lbaStart, LBA_MAX_COUNT):
        nbytes -= leo64dd.size_of_lba(disk_type, i)
        if (nbytes <= 0):
            break
    nbytes += leo64dd.size_of_lba(disk_type, i)

    lbaCount = i + 1 - lbaStart
    lbaEnd = lbaStart + lbaCount

    for lba in range(lbaStart, lbaEnd - 1):
        romBA.extend(disk_obj.get_lba(lba))

    romBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])

    romDecodedBA = leo_decode(romBA)

    # Overlays

    for i in range(0, 13):
        lbaStart = OVERLAY_BLOCKS[i] + RESERVED_BLOCK_COUNT
        vram = OVERLAY_VRAM_JP[i]
        nbytes = vram[1] - vram[0]
        for i in range(lbaStart, LBA_MAX_COUNT):
            nbytes -= leo64dd.size_of_lba(disk_type, i)
            if (nbytes <= 0):
                break
        nbytes += leo64dd.size_of_lba(disk_type, i)
        lbaCount = i + 1 - lbaStart
        lbaEnd = lbaStart + lbaCount
        for lba in range(lbaStart, lbaEnd - 1):
            romDecodedBA.extend(disk_obj.get_lba(lba))

        romDecodedBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])

    # Disk Assets

    for i in range(0, 2):
        lbaStart = ASSET_BLOCKS[i] + RESERVED_BLOCK_COUNT
        vram = ASSET_VRAM_JP[i]
        nbytes = vram[1] - vram[0]
        for i in range(lbaStart, LBA_MAX_COUNT):
            nbytes -= leo64dd.size_of_lba(disk_type, i)
            if (nbytes <= 0):
                break
        nbytes += leo64dd.size_of_lba(disk_type, i)
        lbaCount = i + 1 - lbaStart
        lbaEnd = lbaStart + lbaCount
        for lba in range(lbaStart, lbaEnd - 1):
            romDecodedBA.extend(disk_obj.get_lba(lba))

        romDecodedBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])

    # Disk Courses

    for i in range(COURSE_BLOCK_FIRST, COURSE_BLOCK_FINAL + 1):
        lbaStart = i + RESERVED_BLOCK_COUNT
        nbytes = COURSE_SIZE
        for i in range(lbaStart, LBA_MAX_COUNT):
            nbytes -= leo64dd.size_of_lba(disk_type, i)
            if (nbytes <= 0):
                break
        nbytes += leo64dd.size_of_lba(disk_type, i)
        lbaCount = i + 1 - lbaStart
        lbaEnd = lbaStart + lbaCount
        for lba in range(lbaStart, lbaEnd - 1):
            romDecodedBA.extend(disk_obj.get_lba(lba))

        romDecodedBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])

    # Disk Ghosts

    for i in range(GHOST_BLOCK_FIRST, GHOST_BLOCK_FINAL + 1):
        lbaStart = i + RESERVED_BLOCK_COUNT
        nbytes = GHOST_SIZE
        for i in range(lbaStart, LBA_MAX_COUNT):
            nbytes -= leo64dd.size_of_lba(disk_type, i)
            if (nbytes <= 0):
                break
        nbytes += leo64dd.size_of_lba(disk_type, i)
        lbaCount = i + 1 - lbaStart
        lbaEnd = lbaStart + lbaCount
        for lba in range(lbaStart, lbaEnd - 1):
            romDecodedBA.extend(disk_obj.get_lba(lba))

        romDecodedBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])

    # Disk Audio

    for i in range(0, 3):
        lbaStart = AUDIO_BLOCKS[i] + RESERVED_BLOCK_COUNT
        nbytes = AUDIO_SIZES[i]
        for i in range(lbaStart, LBA_MAX_COUNT):
            nbytes -= leo64dd.size_of_lba(disk_type, i)
            if (nbytes <= 0):
                break
        nbytes += leo64dd.size_of_lba(disk_type, i)
        lbaCount = i + 1 - lbaStart
        lbaEnd = lbaStart + lbaCount
        for lba in range(lbaStart, lbaEnd - 1):
            romDecodedBA.extend(disk_obj.get_lba(lba))

        romDecodedBA.extend(disk_obj.get_lba(lbaEnd - 1)[0:nbytes])
    

    rom.write_bytes(romDecodedBA)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Extracts an fzerox-expansion disk file to z64dd")
    parser.add_argument("--file", help="Baserom file (.ndd/.mame/.d64)", required=True)
    parser.add_argument("--version", help="Version (e.g. jp)", required=True)
    parser.add_argument("--revision", help="Revision (e.g. ek)", required=True)
    args = parser.parse_args()
    main(args)

