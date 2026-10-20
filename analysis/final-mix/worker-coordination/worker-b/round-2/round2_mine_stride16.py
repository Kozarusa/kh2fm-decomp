#!/usr/bin/env python3
"""Mine the original FM ELF for stack-save stride patterns.

Some original KH2FM functions place their callee-saved register slots with a
16-byte stride (sd s0,0(sp) / sd s1,16(sp) / sd s2,32(sp) ...) while the common
pattern is an 8-byte stride. This script lists every such function so recovered
sources of already-registered functions can be compared against them.
"""
import struct
import sys
from pathlib import Path

ELF = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75')
REGISTRY = Path(r'C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/functions.tsv')
MAIN_FOFF = 0x1000
MAIN_VADDR = 0x100000


def be(hex_word: str) -> bytes:
    """Return the little-endian file bytes of a big-endian instruction word."""
    return bytes.fromhex(hex_word)[::-1]


def load_aliases() -> dict:
    aliases = {}
    for line in REGISTRY.read_text().splitlines():
        if not line or line.startswith('#') or '\t' not in line:
            continue
        symbol, addr = line.rsplit('\t', 1)
        aliases.setdefault(addr.strip(), symbol.strip())
    return aliases


def scan_stride16(aliases: dict) -> list:
    blob = ELF.read_bytes()
    size = len(blob)
    hits = []
    # addiu sp,sp,-N  ; sd s0,0(sp) ; sd s1,16(sp) ; sd s2,32(sp)
    prologue = None
    save0 = be('ffb00000')
    save1 = be('ffb10010')
    for off in range(0, size - 32):
        word = blob[off:off + 4]
        if word[1] != 0xff or word[2] != 0xbd or word[3] != 0x27:
            continue
        if blob[off + 4:off + 8] != save0:
            continue
        if blob[off + 8:off + 12] != save1:
            continue
        addr = off - MAIN_FOFF + MAIN_VADDR
        hits.append((f'{addr:08x}', aliases.get(f'{addr:08x}', '<unregistered>'),
                     struct.unpack('<i', word)[0]))
    return hits


def main(_argv: list) -> int:
    aliases = load_aliases()
    hits = scan_stride16(aliases)
    print(f'stride-16 prologue hits: {len(hits)}')
    for addr, symbol, frame in hits[:80]:
        print(f'  {addr}  frame={-frame:3d}  {symbol}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
