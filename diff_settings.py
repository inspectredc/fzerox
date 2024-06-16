#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.us.rev0.z64'
    config['myimg'] = 'build/fzerox.us.rev0.uncompressed.z64'
    config['mapfile'] = 'build/fzerox.us.rev0.map'
    config['source_directories'] = ['./src','./include']
    config['objdump_flags'] = ['-M','reg-names=32']
    config['makeflags'] = ["KEEP_MDEBUG=1"]
