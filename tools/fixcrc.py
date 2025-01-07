import sys
import argparse
import struct

VERBOSE = False

def int32(x):
    return x & 0xFFFFFFFF


def rol(i, b):
    return int32((i << b) | (i >> (32 - b)))


def calculate_crcs(buffer: bytearray, seed=0x1FEA617A, start=0x1000, end=0x101000):
    t1 = t2 = t3 = t4 = t5 = t6 = seed

    for d, in struct.iter_unpack(">I", buffer[start:end]):
        r = rol(d, d & 0x1F)

        if int32(t6 + d) < t6:
            t4 = int32(t4 + 1)

        t3 ^= d
        t6 = int32(t6 + d)
        t2 ^= r if (t2 > d) else t6 ^ d
        t5 = int32(t5 + r)
        t1 = int32(t1 + (t5 ^ d))

    return (int32(t6 * t4 + t3), int32(t5 * t2 + t1))

def fix_crc(rom):
    with open(rom, 'r+b') as romfile:
        crc1, crc2 = calculate_crcs(romfile.read())
    
        romfile.seek(0x10)

        romfile.write(crc1.to_bytes( 4, 'big'))
        romfile.write(crc2.to_bytes( 4, 'big'))
    return

def main(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('rom', help="rom name")

    args = parser.parse_args()

    VERBOSE = args.verbose

    fix_crc(args.rom)
    
    sys.exit()


if __name__ == "__main__":
    main(sys.argv[1:])
