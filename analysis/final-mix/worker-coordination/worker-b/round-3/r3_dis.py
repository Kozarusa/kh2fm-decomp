#!/usr/bin/env python3
"""Decode a verification JSON row's target and compiled hex as MIPS words.

Usage: python3 r3_dis.py <file>.verification.json [address ...]
Prints T (target/original) and C (compiled) big-endian words side by side with
the decoded mnemonic, so a diff can be read without hand-decoding hex.
"""
import json
import sys

R = ('zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3',
     't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
     's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7',
     't8', 't9', 'k0', 'k1', 'gp', 'sp', 'fp', 'ra')
SPECIAL = {0x20: 'add', 0x21: 'addu', 0x22: 'sub', 0x23: 'subu',
           0x24: 'and', 0x25: 'or', 0x26: 'xor', 0x27: 'nor',
           0x2a: 'slt', 0x2b: 'sltu'}
SHIFT = {0x00: 'sll', 0x02: 'srl', 0x03: 'sra'}


def dec(w):
    op = w >> 26
    rs = R[(w >> 21) & 31]
    rt = R[(w >> 16) & 31]
    rd = R[(w >> 11) & 31]
    sa = (w >> 6) & 31
    fn = w & 63
    if w == 0:
        return 'nop'
    if op == 0:
        if fn == 0 and w >> 21 == 0:
            return f'sll {rd},{rt},{sa}'
        if fn == 0:
            return f'mov {rd},{rt}'
        if fn == 2:
            return f'srl {rd},{rt},{sa}'
        if fn == 3:
            return f'sra {rd},{rt},{sa}'
        if fn == 8:
            return f'jr {rt}'
        if fn == 9:
            return f'jalr {rt}'
        if fn == 0x0c:
            return 'syscall'
        if fn == 0x0d:
            return 'break'
        if fn == 0x10:
            return f'mfhi {rd}'
        if fn == 0x12:
            return f'mflo {rd}'
        if fn == 0x18:
            return f'mult {rs},{rt}'
        if fn == 0x19:
            return f'multu {rs},{rt}'
        if fn == 0x1a:
            return f'div {rs},{rt}'
        if fn == 0x1b:
            return f'divu {rs},{rt}'
        if fn in (0x24, 0x25, 0x26, 0x27):
            return f'{SPECIAL[fn]} {rd},{rs},{rt}'
        if fn in (0x2a, 0x2b):
            return f'{SPECIAL[fn]} {rd},{rs},{rt}'
        return f'spec_{fn:02x} rd={rd} rs={rs} rt={rt} sa={sa}'
    if op == 1:
        if rt == 0:
            return f'bltz {rs},{w & 0x3ffffff}'
        if rt == 1:
            return f'bgez {rs},{w & 0x3ffffff}'
        if rt == 16:
            return f'bltzal {rs},{w & 0x3ffffff}'
        if rt == 17:
            return f'bgezal {rs},{w & 0x3ffffff}'
        if fn := (w & 0x3f):
            return f'regimm{fn} {rs},{rt}'
        return f'special1 op={op}'
    if op == 2:
        return f'j {((w & 0x3ffffff) << 2) | 0x1000000:08x}'
    if op == 3:
        return f'jal {((w & 0x3ffffff) << 2) | 0x1000000:08x}'
    if op == 4:
        if rt == 0 and rs == 0:
            return f'b {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0 and rs == 1:
            return f'bgez {rt},{w & 0x3ffffff:+#x}'
        if rt == 0x10 and rs == 0:
            return f'bc0f {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0x11 and rs == 0:
            return f'bc1f {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0x11 and rs == 2:
            return f'bc1t {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0x10 and rs == 1:
            return f'bc1tl {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0x11 and rs == 3:
            return f'bc1tl {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0x11 and rs == 5:
            return f'bc1t16 {(w & 0x3ffffff) << 2:+#x}'
        if rt == 0:
            return f'beq {rs},{rt},{(w & 0x3ffff) << 2:+#x}'
        if rt == 1:
            return f'bne {rs},{rt},{(w & 0x3ffff) << 2:+#x}'
        if rt == 2:
            return f'blez {rs},{(w & 0x3ffff) << 2:+#x}'
        if rt == 3:
            return f'bgtz {rs},{(w & 0x3ffff) << 2:+#x}'
        if rt == 0x10:
            return f'slti {rt},{rs},{w & 0xffff}'
        if rt == 0x11:
            return f'sltiu {rt},{rs},{w & 0xffff}'
        if rt == 0x0c:
            return f'andi {rt},{rs},{w & 0xffff}'
        if rt == 0x0d:
            return f'ori {rt},{rs},{w & 0xffff}'
        if rt == 0x0e:
            return f'xori {rt},{rs},{w & 0xffff}'
        if rt == 0x0f:
            return f'lui {rt},0x{w & 0xffff:04x}'
        return f'op4 rt={rt} rs={rs} imm=0x{w & 0xffff:04x}'
    if op == 0x10:
        return f'cop2 0x{w & 0x1ffffff:07x}'
    if op == 0x11:
        return f'cop1 0x{w & 0x1ffffff:07x}'
    return f'op{op} 0x{w & 0xffffff:06x}'


def cop1(w):
    rs = (w >> 21) & 31
    rt = (w >> 16) & 31
    fs = (w >> 11) & 31
    fd = (w >> 6) & 31
    fn = w & 63
    if fn == 0x00:
        return f'mfc1 {R[rt]},$f{fs}'
    if fn == 0x01:
        return f'dmfc1 {R[rt]},$f{fs}'
    if fn == 0x04:
        return f'mtc1 {R[rt]},$f{fs}'
    if fn == 0x05:
        return f'dmtc1 {R[rt]},$f{fs}'
    if fn == 0x08:
        return f'bc1f {(w & 0x1ffff) << 2:+#x}'
    if fn == 0x09:
        return f'bc1t {(w & 0x1ffff) << 2:+#x}'
    if fn == 0x11:
        return f'mov.s $f{fd},$f{fs}'
    if fn == 0x21:
        return f'add.s $f{fd},$f{fs},$f{rt}'
    if fn == 0x24:
        return f'sub.s $f{fd},$f{fs},$f{rt}'
    if fn == 0x25:
        return f'mul.s $f{fd},$f{fs},$f{rt}'
    if fn == 0x27:
        return f'sqrt.s $f{fd},$f{fs}'
    if fn == 0x32:
        return f'c.eq.s $f{fs},$f{rt}'
    return f'cop1.s fn=0x{fn:02x} fd={fd} fs={fs} rt={rt}'


def words(hexstr):
    """Split a hex blob into big-endian words.

    The verification JSON stores the original ELF bytes verbatim, which are
    little-endian on disk, so each 4-byte group must be byte-reversed before it
    can be decoded (and before it matches the objdump output).
    """
    out = []
    for i in range(0, len(hexstr), 8):
        g = hexstr[i:i + 8]
        if len(g) < 8:
            continue
        out.append(g[6:8] + g[4:6] + g[2:4] + g[0:2])
    return out


def main():
    doc = json.load(open(sys.argv[1]))
    want = set(a.lower() for a in sys.argv[2:])
    for row in doc['rows']:
        addr = str(row['address']).lower()
        if want and addr not in want:
            continue
        tw = words(row['target_hex'])
        cw = words(row['compiled_hex'])
        print(f"##### {addr} exact={row.get('exact_match')} "
              f"{row.get('compiled_size')}/{row.get('target_size')} bytes")
        n = max(len(tw), len(cw))
        for i in range(n):
            a = tw[i] if i < len(tw) else '--------'
            b = cw[i] if i < len(cw) else '--------'
            mark = ' ' if a == b else '*'
            def d(h):
                return dec(int(h, 16)) if h != '--------' else ''
            def d2(h):
                if h == '--------':
                    return ''
                s = dec(int(h, 16))
                return cop1(int(h, 16)) if s.startswith('cop1') else s
            print(f" {mark} {i} T {a} {d(a):<28} C {b} {d2(b)}")


if __name__ == '__main__':
    main()