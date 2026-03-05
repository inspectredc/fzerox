#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.us.rev0.z64'
    config['myimg'] = 'build/us/rev0/fzerox.us.rev0.z64'
    config['mapfile'] = 'build/us/rev0/fzerox.us.rev0.map'

    # config['baseimg'] = 'baserom.jp.ek.z64dd'
    # config['myimg'] = 'build/jp/ek/fzerox-expansion.jp.ek.z64dd'
    # config['mapfile'] = 'build/jp/ek/fzerox-expansion.jp.ek.map'

    config['source_directories'] = ['./src','./include']
    config['objdump_flags'] = ['-M','reg-names=32']
    config['makeflags'] = ["KEEP_MDEBUG=1"]
