"""Decode global-symbol values straight from the raw instruction words of a target range.

ee-objdump's printed lw/sw displacement is unreliable (round 10's 002f1898 proved the printed
-16176 disagrees with the encoded 0xc0d0 = -16192), so every symbol this worker B declares is
derived from the encoded word itself.
"""
import sys

R = ['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7',
     's0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']


def decode(path):
    blob = ''.join(open(path).read().split())
    words = [int.from_bytes(bytes.fromhex(blob[i:i + 8]), 'little') for i in range(0, len(blob), 8)]
    base = None
    for i, w in enumerate(words):
        op = w >> 26
        rs = (w >> 21) & 0x1f
        rt = (w >> 16) & 0x1f
        imm = w & 0xffff
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0x0f:  # lui
            print('%2d  lui     %s,0x%x' % (i, R[rt], imm))
        elif op == 0x23:  # lw
            print('%2d  lw      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x2b:  # sw
            print('%2d  sw      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x37:  # ld
            print('%2d  ld      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x3f:  # sd
            print('%2d  sd      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op in (0x08, 0x09):  # addiu / addi
            print('%2d  add%s %s,%s,%d' % (i, 'iu' if op == 9 else 'i', R[rt], R[rs], simm))
        elif op == 0x0c:  # andi
            print('%2d  andi    %s,%s,0x%x' % (i, R[rt], R[rs], imm))
        elif op == 0x0d:  # ori
            print('%2d  ori     %s,%s,0x%x' % (i, R[rt], R[rs], imm))
        elif op == 0x0e:  # xori
            print('%2d  xori    %s,%s,0x%x' % (i, R[rt], R[rs], imm))
        elif op == 0x24:  # lbu
            print('%2d  lbu     %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x28:  # sb
            print('%2d  sb      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op in (0x20, 0x21):  # lb/lh
            print('%2d  l%sh    %s,%d(%s)' % (i, 'b' if op == 0x20 else 'h', R[rt], simm, R[rs]))
        elif op == 0x29:  # sh
            print('%2d  sh      %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x25:  # lhu
            print('%2d  lhu     %s,%d(%s)' % (i, R[rt], simm, R[rs]))
        elif op == 0x02 or op == 0x03:  # j / jal
            print('%2d  %s      0x%08x' % (i, 'jal' if op == 3 else 'j', (w & 0x3ffffff) << 2))
        elif op == 0x04:  # beq
            print('%2d  beq     %s,%s,%+d' % (i, R[rs], R[rt], simm))
        elif op == 0x05:  # bne
            print('%2d  bne     %s,%s,%+d' % (i, R[rs], R[rt], simm))
        elif op == 0x01:
            print('%2d  (regimm)0x%x' % (i, w & 0x3f))
        elif op == 0 and (w & 0x3f) == 0 and ((w >> 21) & 0x1f):
            print('%2d  jalr    %s' % i, )
        elif op == 0 and (w & 0x3f) == 9:
            print('%2d  jalr    %s' % (i, R[(w >> 21) & 0x1f]))
        elif op == 0 and (w & 0x3f) == 0x21:
            print('%2d  addu    %s,%s,%s' % (i, R[(w >> 11) & 0x1f], R[rs], R[rt]))
        elif op == 0 and (w & 0x3f) == 0x25:
            print('%2d  or      %s,%s,%s' % (i, R[(w >> 11) & 0x1f], R[rs], R[rt]))
        elif op == 0:
            print('%2d  (special f=0x%x)' % (i, w & 0x3f))
        else:
            print('%2d  op=0x%02x 0x%08x' % (i, op, w))


if __name__ == '__main__':
    for p in sys.argv[1:]:
        print('=== ' + p)
        decode(p)