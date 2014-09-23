# -*- mode: python -*-
# vi: set ft=python :

import sys
import os


def options(opt):
        opt.load('compiler_c')


def configure(conf):
    conf.load('compiler_c')
    conf.load('clib')

    if sys.platform == 'win32':
        conf.check_cc(lib='ws2_32')
        conf.check_cc(lib='psapi')

    conf.check_cc(lib='uv', libpath=[os.getcwd()])


def build(bld):
    bld.load('clib')

    if sys.platform == 'win32':
        platform = '-DWIN32'
    elif sys.platform == 'linux2':
        platform = '-DLINUX'
    else:
        platform = ''

    libs = ['uv']
    if sys.platform == 'win32':
        libs += """
                ws2_32
                psapi
                Iphlpapi
                """.split()
    elif sys.platform == 'darwin':
        pass
    else:
        libs += """
                dl
                rt
                pthread
                """.split()

    cli_clibs = """
        file2str
        stubfile
        tracker-client
        torrent-reader
        """.split()

    clibs = """
        yabtorrent
        config-re
        heapless-bencode
        mt19937ar
        """.split() + cli_clibs

    bld.program(
        source="""
            src/filedumper.c
            src/yabtorrent.c
            src/network_adapter_libuv_v0.10.c
            """.split() + bld.clib_c_files(clibs),
        target='bt',
        cflags="""
            -g
            """.split(),
        stlibpath=['.'],
        libpath=[os.getcwd()],
        lib=libs,
        includes=['./include', './libuv/include'] + bld.clib_h_paths(clibs))
