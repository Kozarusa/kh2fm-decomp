#!/usr/bin/env python3
"""Worker B: print raw little-endian words for a vaddr range of an ELF32 file,
translating virtual addresses through the program headers."""
import struct
import sys

path = sys.argv[1]
data = open(path, "rb").read()
phoff = struct.unpack_from("<I", data, 0x1C)[0]
phentsize = struct.unpack_from("<H", data, 0x2A)[0]
phnum = struct.unpack_from("<H", data, 0x2C)[0]


def to_offset(vaddr):
    for i in range(phnum):
        off = phoff + i * phentsize
        p_type, p_offset, p_vaddr, _p_paddr, p_filesz, _p_memsz, _p_flags, _p_align = \
            struct.unpack_from("<8I", data, off)
        if p_type == 1 and p_vaddr <= vaddr < p_vaddr + p_filesz:
            return p_offset + (vaddr - p_vaddr)
    raise SystemExit("vaddr %08x not mapped" % vaddr)


base = int(sys.argv[2], 16)
end = int(sys.argv[3], 16)
v = base
while v < end:
    o = to_offset(v)
    print("%08x  %08x" % (v, int.from_bytes(data[o:o + 4], "little")))
    v += 4