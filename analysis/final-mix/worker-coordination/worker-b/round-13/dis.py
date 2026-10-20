import json, sys

N = {0:'zero',1:'at',2:'v0',3:'v1',4:'a0',5:'a1',6:'a2',7:'a3',8:'t0',9:'t1',10:'t2',11:'t3',
     12:'t4',13:'t5',14:'t6',15:'t7',16:'s0',17:'s1',18:'s2',19:'s3',20:'s4',21:'s5',22:'s6',
     23:'s7',28:'gp',29:'sp',30:'fp',31:'ra'}

SPECIAL = {0:'sll',2:'srl',3:'sra',4:'sllv',6:'srlv',7:'srav',9:'jalr',0x21:'addu',0x25:'or',
           0x2a:'slt',0x2b:'sltu',0x2d:'slt',0x24:'and',0x26:'xor'}


def sign(imm):
    return imm - 0x10000 if imm & 0x8000 else imm


def dec(w):
    op = w >> 26
    rs = (w >> 21) & 0x1f
    rt = (w >> 16) & 0x1f
    imm = w & 0xffff
    off = (w & 0xffff) << 2
    if op == 3:
        return 'jal 0x%08x' % ((w & 0x3ffffff) << 2)
    if op == 2:
        return 'j 0x%08x' % ((w & 0x3ffffff) << 2)
    if op == 4:
        return 'beq %s,%s,0x%x' % (N[rs], N[rt], imm)
    if op == 5:
        return 'bne %s,%s,0x%x' % (N[rs], N[rt], imm)
    if op == 6:
        return 'blez %s,0x%x' % (N[rs], imm)
    if op == 7:
        return 'bgtz %s,0x%x' % (N[rs], imm)
    if op == 1:
        if rt in (0, 0x10):
            return ('bgez' if imm & 0x8000 else 'bltz') + ' %s' % N[rs]
        if rt in (1, 0x11):
            return ('bgezal' if imm & 0x8000 else 'bltzal') + ' %s' % N[rs]
        return 'regimm rt=%d %s imm=0x%x' % (rt, N[rs], imm)
    if op in (0x2f, 0x37) and (w & 0x1f) == 0:
        return '%s %s,%d(%s)' % ('sd' if op == 0x2f else 'ld', N[rt], sign(imm), N[rs])
    if op == 0x2f:
        return 'sd %s,%d(%s)' % (N[rt], sign(imm), N[rs])
    if op == 0x37:
        return 'ld %s,%d(%s)' % (N[rt], sign(imm), N[rs])
    if op in (0x23, 0x2b):
        return '%s %s,%d(%s)' % ('lw' if op == 0x23 else 'sw', N[rt], sign(imm), N[rs])
    if op in (0x20, 0x28, 0x21, 0x25, 0x24, 0x26):
        return '%s %s,%s,%s' % ({0x20:'lb',0x28:'sb',0x21:'lh',0x25:'sh',0x24:'lbu',0x26:'lhu'}[op],
                                N[rt], N[rs], N[(w >> 11) & 0x1f])
    if op == 0x2b:
        return 'sw'
    if op == 0x0f:
        return 'lui %s,0x%x' % (N[rt], imm)
    if op == 0x0d:
        return 'ori %s,%s,0x%x' % (N[rt], N[rs], imm)
    if op == 0x0c:
        return 'andi %s,%s,0x%x' % (N[rt], N[rs], imm)
    if op == 0x0e:
        return 'xori %s,%s,0x%x' % (N[rt], N[rs], imm)
    if op == 9:
        return 'addiu %s,%s,%d' % (N[rt], N[rs], sign(imm))
    if op == 0x0a:
        return 'slti %s,%s,%d' % (N[rt], N[rs], sign(imm))
    if op == 0x0b:
        return 'sltiu %s,%s,%d' % (N[rt], N[rs], sign(imm))
    if op == 0:
        f = w & 0x3f
        return '%s %s,%s,%s' % (SPECIAL.get(f, 'spec0x%x' % f), N[(w >> 11) & 0x1f], N[rt], N[rs])
    return 'op%02x %08x' % (op, w)


def words(d, key):
    h = ''.join(d[key].split())
    return [int.from_bytes(bytes.fromhex(h[i:i + 8]), 'little') for i in range(0, len(h), 8)]


def dump(path, labels=('target_hex', 'compiled_hex')):
    rows = json.load(open(path))['rows']
    d = rows[0]
    t = words(d, labels[0]) if labels[0] in d else []
    c = words(d, labels[1]) if labels[1] in d else []
    print('#### %s  %s/%s exact=%s boundary=%s' % (path, d['compiled_size'], d['target_size'],
                                                     d.get('exact_match'), d.get('boundary_agreement')))
    for i in range(max(len(t), len(c))):
        tw = t[i] if i < len(t) else None
        cw = c[i] if i < len(c) else None
        print('  %2d %-9s %-26s | %-9s %-26s %s' % (
            i, ('%08x' % tw) if tw is not None else '--', dec(tw) if tw is not None else '',
            ('%08x' % cw) if cw is not None else '--', dec(cw) if cw is not None else '',
            '' if tw == cw else '<<<'))
    return t, c


if __name__ == '__main__':
    for p in sys.argv[1:]:
        dump(p)