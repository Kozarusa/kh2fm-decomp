"""Decode a hex instruction stream as big-endian MIPS III / R5900 (PS2 EE) words.

Worker B analysis helper. It is advisory tooling only: it never replaces the
compiler gate in tools/kh2-audit/probe_fm_source.py. Instructions it does not
know are printed as .word with their raw encoding so nothing is silently lost.

Usage:
    python disasm_r5900.py <hex>            # decode a hex string
    python disasm_r5900.py --file <path>    # decode a whitespace/hexdump file
"""
import re
import sys

REG = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3',
       't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
       's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7',
       't8', 't9', 'k0', 'k1', 'k2', 'k3', 'k4', 'k5', 'k6', 'k7',
       'gp', 'sp', 'fp', 'ra']

SPECIAL = {
    0x00: 'sll', 0x02: 'srl', 0x03: 'sra', 0x04: 'sllv', 0x06: 'srlv',
    0x07: 'srav', 0x08: 'jr', 0x09: 'jalr', 0x0a: 'movz', 0x0b: 'movn',
    0x0c: 'syscall', 0x0d: 'break', 0x0f: 'sync', 0x10: 'mfhi', 0x11: 'mthi',
    0x12: 'mflo', 0x13: 'mtlo', 0x18: 'mult', 0x19: 'multu', 0x1a: 'div',
    0x1b: 'divu', 0x20: 'add', 0x21: 'addu', 0x22: 'sub', 0x23: 'subu',
    0x24: 'and', 0x25: 'or', 0x26: 'xor', 0x27: 'nor', 0x2a: 'slt',
    0x2b: 'sltu',
}

REGIMM = {0x00: 'bltz', 0x01: 'bgez', 0x10: 'bltzal', 0x11: 'bgezal'}

SPECIAL2 = {0x00: 'madd', 0x01: 'maddu', 0x04: 'msub', 0x05: 'msubu',
            0x20: 'clz', 0x21: 'clo'}

COP0 = {0x00: 'mfc0', 0x04: 'mtc0', 0x10: 'cop0_co'}


def sext(value, bits):
    sign = 1 << (bits - 1)
    return (value & (sign - 1)) - (value & sign)


def decode(word):
    op = word >> 26
    rs = (word >> 21) & 0x1F
    rt = (word >> 16) & 0x1F
    rd = (word >> 11) & 0x1F
    sa = (word >> 6) & 0x1F
    funct = word & 0x3F
    imm = word & 0xFFFF
    simm = sext(imm, 16)
    target = word & 0x3FFFFFF
    if word == 0:
        return 'nop'
    if op == 0:
        name = SPECIAL.get(funct)
        if name is None and word >> 16 in SPECIAL2:
            name = SPECIAL2[word >> 16]
        if name is None:
            return f'.word 0x{word:08x}   ; special funct=0x{funct:02x}'
        if name in ('sll', 'srl', 'sra'):
            if word == 0:
                return 'nop'
            return f'{name} {REG[rd]}, {REG[rt]}, {sa}'
        if name in ('sllv', 'srlv', 'srav'):
            return f'{name} {REG[rd]}, {REG[rt]}, {REG[rs]}'
        if name == 'jr':
            return f'jr {REG[rs]}'
        if name == 'jalr':
            return f'jalr {REG[rd]}, {REG[rs]}'
        if name in ('movz', 'movn'):
            return f'{name} {REG[rd]}, {REG[rs]}, {REG[rt]}'
        if name in ('syscall', 'break'):
            return f'{name} 0x{(word >> 6) & 0xFFFFF:05x}'
        if name == 'sync':
            return f'sync 0x{sa:02x}'
        if name in ('mfhi', 'mflo'):
            return f'{name} {REG[rd]}'
        if name in ('mthi', 'mtlo'):
            return f'{name} {REG[rs]}'
        if name in ('mult', 'multu', 'div', 'divu'):
            return f'{name} {REG[rs]}, {REG[rt]}'
        if name == 'madd':
            return f'madd {REG[rs]}, {REG[rt]}'
        if name in ('clz', 'clo'):
            return f'{name} {REG[rd]}, {REG[rt]}'
        return f'{name} {REG[rd]}, {REG[rs]}, {REG[rt]}'
    if op == 1:
        name = REGIMM.get(rt)
        if name is None:
            return f'.word 0x{word:08x}   ; regimm rt=0x{rt:02x}'
        return f'{name} {REG[rs]}, {simm}'
    if op == 0x10:
        name = COP0.get(rs)
        if name == 'mfc0':
            return f'mfc0 {REG[rt]}, cop0r{rd}'
        if name == 'mtc0':
            return f'mtc0 {REG[rt]}, cop0r{rd}'
        return f'.word 0x{word:08x}   ; cop0 rs=0x{rs:02x}'
    if op in (2, 3):
        return f'{"j" if op == 2 else "jal"} 0x{target << 2:08x}'
    if op in (4, 5, 6, 7):
        name = {4: 'beq', 5: 'bne', 6: 'blez', 7: 'bgtz'}[op]
        if name in ('blez', 'bgtz'):
            return f'{name} {REG[rs]}, {simm}'
        return f'{name} {REG[rs]}, {REG[rt]}, {simm}'
    if op in (8, 9, 10, 11, 12, 13, 14, 15):
        name = {8: 'addi', 9: 'addiu', 10: 'slti', 11: 'sltiu', 12: 'andi',
                13: 'ori', 14: 'xori', 15: 'lui'}[op]
        if name == 'lui':
            return f'lui {REG[rt]}, 0x{imm:04x}'
        if name in ('andi', 'ori', 'xori'):
            return f'{name} {REG[rt]}, {REG[rs]}, 0x{imm:04x}'
        return f'{name} {REG[rt]}, {REG[rs]}, {simm}'
    if op == 0x1C:
        name = {0: 'ext', 4: 'ins', 0x20: 'wsbh', 0x22: 'seb', 0x23: 'seh'}.get(rs)
        if name is None:
            return f'.word 0x{word:08x}   ; special2 rs=0x{rs:02x}'
        if name in ('wsbh', 'seb', 'seh'):
            return f'{name} {REG[rd]}, {REG[rt]}'
        if name == 'ext':
            return f'ext {REG[rt]}, {REG[rs]}, {sa}, {rd + 1}'
        return f'ins {REG[rt]}, {REG[rs]}, {sa}, {rd - sa + 1}'
    if op in (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B):
        name = {0x20: 'lb', 0x21: 'lh', 0x23: 'lw', 0x24: 'lbu', 0x25: 'lhu',
                0x28: 'sb', 0x29: 'sh', 0x2B: 'sw'}[op]
        return f'{name} {REG[rt]}, {simm}({REG[rs]})'
    if op == 0x2F:
        return f'cache 0x{rt:02x}, {simm}({REG[rs]})'
    # COP1: GPR[rs] is the address, GPR[rt] names the FPR.
    cop1 = {0x31: 'lwc1', 0x35: 'ldc1', 0x39: 'swc1', 0x3D: 'sdc1'}
    if op in cop1:
        return f'{cop1[op]} $f{rt}, {simm}({REG[rs]})'
    # COP2 (EE vector unit): these keep register-name spelling only.
    cop2 = {0x30: 'mfc2', 0x32: 'cfc2', 0x34: 'lwc2', 0x3A: 'swc2',
            0x36: 'lwc2_alt', 0x3E: 'ldc2', 0x3F: 'sdc2'}
    if op in cop2:
        return f'{cop2[op]} {REG[rt]}, {simm}({REG[rs]})'
    if op == 0x38:
        return f'sc {REG[rt]}, {simm}({REG[rs]})'
    if op in (0x01, 0x05, 0x09, 0x0D, 0x11, 0x15, 0x19, 0x1D):
        return f'.word 0x{word:08x}   ; regfmt op=0x{op:02x}'
    return f'.word 0x{word:08x}   ; op=0x{op:02x}'


def main():
    if len(sys.argv) > 2 and sys.argv[1] == '--file':
        text = open(sys.argv[2]).read()
    else:
        text = sys.argv[1] if len(sys.argv) > 1 else ''
    words = re.findall(r'[0-9a-fA-F]{8}', re.sub(r'[^0-9a-fA-F]', ' ', text))
    # Rejoin into byte pairs: the scan above finds 8-hex-digit words only.
    for index, word in enumerate(words):
        print(f'{index * 4:08x}  {word}  {decode(int(word, 16))}')


if __name__ == '__main__':
    main()