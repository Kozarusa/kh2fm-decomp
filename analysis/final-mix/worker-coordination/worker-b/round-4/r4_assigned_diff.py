"""Decode the six ASSIGNED round-4 targets from targets.json (no compiler needed).

targets.json carries complete original_hex / compiled_hex plus difference_offsets.
Both are stored byte-reversed per 4-byte group, so each group is reversed before decoding.
"""
import json, sys, os

HERE = os.path.dirname(os.path.abspath(__file__))
OPS = {0x20:'add',0x21:'addu',0x22:'sub',0x23:'subu',0x24:'and',0x25:'or',0x26:'xor',
       0x2a:'slt',0x2b:'sltu',0x00:'sll',0x02:'srl',0x03:'sra',0x04:'sllv',0x06:'srlv',
       0x0c:'jal',0x0d:'jalr',0x08:'jr',0x09:'jalr_alt',0x10:'mfhi',0x18:'mult',
       0x19:'multu',0x1a:'div',0x1b:'divu'}

def words(h):
    b = bytes.fromhex(h)
    assert len(b) % 4 == 0, len(b)
    return [int.from_bytes(b[i:i+4], 'little') for i in range(0, len(b), 4)]

def decode(w):
    op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31; rd = (w >> 11) & 31
    sa = (w >> 6) & 31; fn = w & 63; imm = w & 0xffff
    if imm >= 0x8000: imm -= 0x10000
    R = ['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7',
         's0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
    if w == 0: return 'nop'
    if op == 0:
        if fn == 0x00: return f'sll {R[rd]},{R[rt]},{sa}'
        if fn == 0x02: return f'srl {R[rd]},{R[rt]},{sa}'
        if fn == 0x03: return f'sra {R[rd]},{R[rt]},{sa}'
        if fn == 0x2d: return f'move {R[rd]},{R[rs]}'
        if fn == 0x08: return f'jr {R[rs]}'
        if fn == 0x09: return f'jalr {R[rs]}'
        if fn == 0x21: return f'addu {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x23: return f'subu {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x24: return f'and {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x25: return f'or {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x26: return f'xor {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x38: return f'dsll {R[rd]},{R[rs]},{rt}'
        if fn == 0x3a: return f'dsrl {R[rd]},{R[rs]},{rt}'
        if fn == 0x3b: return f'dsra {R[rd]},{R[rs]},{rt}'
        if fn == 0x3c: return f'dsll32 {R[rd]},{R[rs]},{rt}'
        if fn == 0x3d: return f'dsrl32 {R[rd]},{R[rs]},{rt}'
        if fn == 0x3e: return f'dsra32 {R[rd]},{R[rs]},{rt}'
        if fn == 0x3f: return f'dsra32? {R[rd]},{R[rs]},{rt}'
        if fn == 0x2b: return f'sltu {R[rd]},{R[rs]},{R[rt]}'
        if fn == 0x2a: return f'slt {R[rd]},{R[rs]},{R[rt]}'
        if w >> 26 == 0 and fn == 0 and rs == 0 and rt == 0: return 'sll zero,zero,0'
        return f'spec fn=0x{fn:02x} rd={R[rd]} rs={R[rs]} rt={R[rt]}'
    if op == 2: return f'j 0x{(w & 0x3ffffff) << 2:08x}'
    if op == 3: return f'jal 0x{(w & 0x3ffffff) << 2:08x}'
    if op == 0x10: return f'cop0 0x{(w>>26)&3} rs={R[rs]} rt={R[rt]} 0x{(w&0x3ffffff):06x}'
    if op in (0x11,0x13,0x31,0x35):
        return f'cop{op:02x} 0x{(w&0x3ffffff):06x} rt={R[rt]} rd={R[rd]} sa={sa}'
    if op == 0x04: return f'beq {R[rs]},{R[rt]},{imm:+d}'
    if op == 0x05: return f'bne {R[rs]},{R[rt]},{imm:+d}'
    if op == 0x06: return f'blez {R[rs]},{imm:+d}'
    if op == 0x07: return f'bgtz {R[rs]},{imm:+d}'
    if op == 0x14: return f'beql {R[rs]},{R[rt]},{imm:+d}'
    if op == 0x15: return f'bnel {R[rs]},{R[rt]},{imm:+d}'
    if op == 0x01:
        kinds = {0:'bltz',1:'bgez',2:'?2',3:'?3',0x10:'bltzal',0x11:'bgezal'}
        return f'{kinds.get(rt,hex(rt))} {R[rs]},{imm:+d}'
    if op == 0x09: return f'addiu {R[rt]},{R[rs]},{imm:+d}'
    if op == 0x0d: return f'ori {R[rt]},{R[rs]},0x{imm & 0xffff:04x}'
    if op == 0x0f: return f'lui {R[rt]},0x{(w>>16)&0xffff:04x}'
    if op == 0x0a: return f'slti {R[rt]},{R[rs]},{imm:+d}'
    if op == 0x0b: return f'sltiu {R[rt]},{R[rs]},{imm:+d}'
    if op == 0x0c: return f'andi {R[rt]},{R[rs]},0x{imm & 0xffff:04x}'
    if op == 0x08: return f'addi {R[rt]},{R[rs]},{imm:+d}'
    if op == 0x23: return f'lw {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x21: return f'lh {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x25: return f'lhu {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x24: return f'lbu {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x20: return f'lb {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x28: return f'sw {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x29: return f'sh {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x2b: return f'sb {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x2f: return f'cache rt={R[rt]},off={imm}({R[rs]})'
    if op == 0x37: return f'ld {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x3f: return f'sd {R[rt]},{imm:+d}({R[rs]})'
    if op == 0x33: return f'lwc1 $f{rt},{imm:+d}({R[rs]})'
    if op == 0x39: return f'swc1 $f{rt},{imm:+d}({R[rs]})'
    if op == 0x32: return f'lwc2 $c{rt},{imm:+d}({R[rs]})'
    if op == 0x3a: return f'swc2 $c{rt},{imm:+d}({R[rs]})'
    return f'op=0x{op:02x} raw=0x{w:08x}'

def main():
    only = set(sys.argv[1:])
    d = json.load(open(os.path.join(HERE, 'targets.json')))
    for r in d['targets']:
        a = r['address']
        if only and a not in only: continue
        T = words(r['original_hex']); C = words(r['compiled_hex'])
        print('=' * 78)
        print(f"{a}  size={r['size']}  differing words={r['different_words']}  offsets={r['difference_offsets']}")
        print(f"source: {r['source']}")
        for i in range(max(len(T), len(C))):
            t = T[i] if i < len(T) else None
            c = C[i] if i < len(C) else None
            if t is None or c is None:
                print(f'  {i*4:4d} T={"----" if t is None else "%08x"%t} C={"----" if c is None else "%08x"%c}  (length differs)')
                continue
            mark = ' ' if t == c else '*'
            if t == c:
                print(f'{mark} {i*4:4d} {t:08x}  {decode(t)}')
            else:
                print(f'{mark} {i*4:4d} T {t:08x}  {decode(t):<34} C {c:08x}  {decode(c)}')
        print('--- code ---')
        print(r['code'])

main()
