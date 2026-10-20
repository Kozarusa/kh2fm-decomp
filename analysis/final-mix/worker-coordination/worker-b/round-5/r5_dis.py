#!/usr/bin/env python3
"""R5900 (EE) disassembler for the round-5 word diffs.

Field layout is the vanilla MIPS one (verified against the pinned ee-objdump on
`addiu`, `jr`, `sw`/`lw`, `jal`, `ori`, `lui` and on the R5900 `dsll32`/`dsra32`
words of 0014b950): SPECIAL uses rs=25..21, rt=20..16, rd=15..11, sa=10..6,
funct=5..0; R-type ALU ops take (rd, rs, rt).  DSLL32/DSRA32 shift by 32+sa.
"""
import sys

R = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3',
     't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
     's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7',
     't8', 't9', 'k0', 'k1', 'gp', 'sp', 'fp', 'ra']
SPECIAL = {0x00: ('sll', 0), 0x02: ('srl', 0), 0x03: ('sra', 0), 0x04: ('sllv', 2),
           0x06: ('srlv', 2), 0x07: ('srav', 2), 0x08: ('jr', 1), 0x09: ('jalr', 1),
           0x0c: ('syscall', 0), 0x10: ('mfhi', 0), 0x12: ('mflo', 0),
           0x18: ('mult', 2), 0x19: ('multu', 2), 0x1a: ('div', 2), 0x1b: ('divu', 2),
           0x20: ('add', 2), 0x21: ('addu', 2), 0x22: ('sub', 2), 0x23: ('subu', 2),
           0x24: ('and', 2), 0x25: ('or', 2), 0x26: ('xor', 2), 0x27: ('nor', 2),
           0x2a: ('slt', 2), 0x2b: ('sltu', 2)}
DSPECIAL = {0x00: ('ll', 1), 0x08: ('sc', 1), 0x38: ('dsll', 'd'),
            0x39: ('dsrl', 'd'), 0x3a: ('dsra', 'd'), 0x3b: ('dsll32', 'd32'),
            0x3c: ('dsrl32', 'd32'), 0x3d: ('dsra32', 'd32'), 0x3f: ('dsra', 'd32')}
OP = {0x08: 'addi', 0x09: 'addiu', 0x0a: 'slti', 0x0b: 'sltiu', 0x0c: 'andi',
      0x0d: 'ori', 0x0e: 'xori', 0x0f: 'lui', 0x20: 'lb', 0x21: 'lh', 0x23: 'lw',
      0x24: 'lbu', 0x25: 'lhu', 0x28: 'sb', 0x29: 'sh', 0x2b: 'sw',
      0x30: 'lwc1', 0x38: 'swc1', 0x2f: 'cache', 0x33: 'pref'}
SPECIAL2 = {0x00: ('madd', 4), 0x04: ('msub', 4), 0x20: ('clz', 1), 0x21: ('clo', 1)}


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def dis(w, pc=0):
    op = w >> 26
    rs, rt, rd, sa, fn = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31, w & 63
    if op == 0:
        if fn in SPECIAL:
            name, kind = SPECIAL[fn]
            if kind == 0:
                if name in ('sll', 'srl', 'sra') and w == 0:
                    return 'nop'
                return f'{name} {R[rd]},{R[rt]},{sa}'
            if kind == 1:
                return f'{name} {R[rs]}'
            return f'{name} {R[rd]},{R[rs]},{R[rt]}'
        if fn in DSPECIAL:
            name, kind = DSPECIAL[fn]
            if kind == 1:
                return f'{name} {R[rt]},{s16(w & 0xffff)}({R[rs]})'
            if kind == 'd':
                return f'{name} {R[rd]},{R[rt]},{sa}'
            return f'{name} {R[rd]},{R[rt]},{sa}   # shift {32 + sa}'
        return f'special? 0x{fn:02x}'
    if op == 1:
        return f'{REGIMM.get(rt, "regimm?")} {R[rs]},{s16(w & 0xffff)}'
    if op == 2:
        t = (w & 0x3ffffff) << 2
        return f'j 0x{((pc + 4) & 0xf0000000) | t:08x}'
    if op == 3:
        t = (w & 0x3ffffff) << 2
        return f'jal 0x{((pc + 4) & 0xf0000000) | t:08x}'
    if op == 4:
        return f'beq {R[rs]},{R[rt]},{pc + 4 + 4 * s16(w & 0xffff):08x}'
    if op == 5:
        return f'bne {R[rs]},{R[rt]},{pc + 4 + 4 * s16(w & 0xffff):08x}'
    if op == 6:
        return f'blez {R[rs]},{pc + 4 + 4 * s16(w & 0xffff):08x}'
    if op == 7:
        return f'bgtz {R[rs]},{pc + 4 + 4 * s16(w & 0xffff):08x}'
    if op in (16, 17, 18, 19):
        return f'cop{op - 16} {rs},{rt},{rd}'
    if op == 28:
        if fn in SPECIAL2:
            name, kind = SPECIAL2[fn]
            return (f'{name} {R[rd]},{R[rs]},{R[rt]}' if kind == 4
                    else f'{name} {R[rd]},{R[rs]}')
        return f'special2? 0x{fn:02x}'
    if op == 31:
        return f'special3? 0x{fn:02x}'
    if op == 0x10:  # COP0
        return f'cop0 0x{w & 0x7ffffff:07x}'
    if op in OP:
        name = OP[op]
        if op in (0x23, 0x2b, 0x30, 0x38, 0x2f, 0x33):
            return f'{name} {R[rt]},{s16(w & 0xffff)}({R[rs]})'
        if name == 'lui':
            return f'lui {R[rt]},0x{w & 0xffff:04x}'
        if name in ('andi', 'ori', 'xori'):
            return f'{name} {R[rt]},{R[rs]},0x{w & 0xffff:04x}'
        return f'{name} {R[rt]},{R[rs]},{s16(w & 0xffff)}'
    return f'? 0x{w:08x}'


REGIMM = {0x00: 'bltz', 0x01: 'bgez', 0x10: 'bltzal', 0x11: 'bgezal'}


def decode(hexstr, base=0, reverse=True, label=''):
    b = bytes.fromhex(hexstr)
    out = []
    for i in range(0, len(b), 4):
        w = b[i:i + 4]
        if reverse:
            w = w[::-1]
        word = int.from_bytes(w, 'big')
        out.append(f'  {base + i:08x} +{i:3d} w{i // 4:2d} {word:08x}  '
                   f'{dis(word, base + i)}')
    return '\n'.join(out)


if __name__ == '__main__':
    rev = len(sys.argv) > 3 and sys.argv[3] == 'rev'
    print(decode(sys.argv[1], int(sys.argv[2], 16) if len(sys.argv) > 2 else 0,
                 reverse=rev))
