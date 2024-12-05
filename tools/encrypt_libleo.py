#!/usr/bin/env python3

import sys
import os
import argparse

# Adapted from pret/pokestadium

# Libleo encryptor. v0.4
# called via: encrypt_libleo.py [rom path] [map path]

# Changelog:
# v0.1: It exists. Please read the ROM in and do 1 write rather than 100s though
# v0.2: Refactor to buffer ROM asm into 1 bytearray call for each encrypt for better I/O.
# v0.3: Compact the encrypt function(s).
# v0.4: Cleanup and change vram to rom conversion to appropriate offset for fzerox

# Return a virtual address for a given function.
def get_address_from_map(Lines, name):
    for line in Lines:
        if name in line:
            return line.split()[0]
    return -1 # we didnt find anything. sad day.

# Encrypt a function at a given location of the ROM via the expected libleo
# obfuscation for an encrypted boot function.
def encrypt_func(rom_file, rom_addr, key, numwords):
    rom_file.seek(int(rom_addr, 16), os.SEEK_SET)
    ba = bytearray(rom_file.read(numwords * 4))
    for i in range(0, numwords):
        ba[i * 4 + 2] = (ba[i * 4 + 2] + key) & 0xFF
        ba[i * 4 + 3] = (ba[i * 4 + 3] - key) & 0xFF
    rom_file.seek(int(rom_addr, 16), os.SEEK_SET)
    rom_file.write(ba)
    return 0

def main(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument('rom', help="rom name")
    parser.add_argument('map', help="map name")
    args = parser.parse_args()

    # Open the 2 files
    rom_file = open(args.rom, 'r+b')
    map_file = open(args.map, 'r')

    Lines = map_file.readlines()

    # Find the virtual addresses for each function to encrypt.
    game2_addr = hex(int(get_address_from_map(Lines, "__LeoBootGame2"), 16))
    game3_addr = hex(int(get_address_from_map(Lines, "__LeoBootGame3"), 16))

    game2_rom_addr = hex(int(game2_addr, 16) - 0x80066000)
    game3_rom_addr = hex(int(game3_addr, 16) - 0x80066000)

    game2_addr_int = int(game2_addr, 16)

    # Calculate the encryption key.
    key = ((game2_addr_int & 0xFF000000) >> 0x18) + ((game2_addr_int & 0x00FF0000) >> 0x10) + ((game2_addr_int & 0x0000FF00) >> 0x08) + ((game2_addr_int & 0x000000FF)) & 0xFF

    # TODO: The sizes are hardcoded for __LeoBootGame2 and __LeoBootGame3. TODO: Don't hardcode?
    encrypt_func(rom_file, game2_rom_addr, key, 201) # __LeoBootGame2
    encrypt_func(rom_file, game3_rom_addr, key, 24)  # __LeoBootGame3

    sys.exit()


if __name__ == "__main__":
    main(sys.argv[1:])