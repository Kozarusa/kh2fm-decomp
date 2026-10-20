"""Independent, carefully-written MIPS word decoder used to cross-check the
mnemonics printed by r4_assigned_diff.py before any claim is written down."""
import json, sys

R = ["zero","at","v0","v1","a0","a1","a2","a3",
     "t0","t1","t2","t3","t4","t5","t6","t7",
     "s0","s1","s2","s3","s4","s5","s6","s7",
     "t8","t9","k0","k1","gp","sp","s8","ra"]

SPECIAL = {0x00:"sll",0x02:"srl",0x03:"sra",0x04:"sllv",0x06:"srlv",0x07:"srav",
           0x08:"jr",0x09:"jalr",0x0c:"syscall",0x0d:"break",0x10:"mfhi",0x11:"mthi",
           0x12:"mflo",0x13:"mtlo",0x18:"mult",0x19:"multu",0x1a:"div",0x1b:"divu",
           0x20:"add",0x21:"addu",0x22:"sub",0x23:"subu",0x24:"and",0x25:"or",
           0x26:"xor",0x27:"nor",0x2a:"slt",0x2b:"sltu",0x2d:"mov"}
OP = {0x02:"j",0x03:"jal",0x04:"beq",0x05:"bne",0x06:"blez",0x07:"bgtz",
      0x08:"addi",0x09:"addiu",0x0a:"slti",0x0b:"sltiu",0x0c:"andi",0x0d:"ori",
      0x0e:"xori",0x0f:"lui",
      0x10:"cop0",0x14:"beql",0x15:"bnel",
      0x20:"lb",0x21:"lh",0x22:"lwl",0x23:"lw",0x24:"lbu",0x25:"lhu",0x26:"lwr",
      0x28:"sb",0x29:"sh",0x2a:"swl",0x2b:"sw",0x2c:"sdl",0x2d:"sd",0x2e:"swr",0x2f:"sdr",
      0x30:"ll",0x38:"sc",0x37:"ld",
      0x31:"lwc1",0x35:"ldc1",0x39:"swc1",0x3d:"sdc1"}
# R5900 64-bit shift family. The operand field order differs from vanilla MIPS and
# I have NOT verified it against the pinned ee-objdump, so these decode as "?".
SPECIAL_R5900 = {0x38:"dsll?",0x3a:"dsrl?",0x3b:"dsra?",
                 0x3c:"dsll32?",0x3d:"dsra32?",0x3e:"dsrl32?",0x3f:"dsrl32?"}


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def dec(w):
    op = (w >> 26) & 0x3f
    rs = (w >> 21) & 0x1f
    rt = (w >> 16) & 0x1f
    imm = w & 0xffff
    if w == 0:
        return "nop"
    if op == 0:
        rd = (w >> 11) & 0x1f
        sa = (w >> 6) & 0x1f
        fn = w & 0x3f
        if fn in SPECIAL:
            n = SPECIAL[fn]
            if fn == 0x00 and w == 0:
                return "nop"
            if fn in (0x08, 0x09):
                return "%-5s %s" % (n, R[rs])
            if fn in (0x00, 0x02, 0x03):
                return "%-5s %s,%s,%d" % (n, R[rd], R[rt], sa)
            if fn in (0x18, 0x19, 0x1a, 0x1b):
                return "%-5s %s,%s" % (n, R[rs], R[rt])
            if fn == 0x2d:
                return "%-5s %s,%s" % (n, R[rd], R[rs])
            return "%-5s %s,%s,%s" % (n, R[rd], R[rs], R[rt])
        if fn in SPECIAL_R5900:
            return "%-9s (unverified R5900 shift fields)" % SPECIAL_R5900[fn]
        return "special.?fn=0x%02x" % fn
    if op in OP:
        n = OP[op]
        if n in ("j", "jal"):
            return "%-5s 0x%08x" % (n, (w & 0x3ffffff) << 2)
        if n in ("beq", "bne", "beql", "bnel"):
            return "%-5s %s,%s,%+d" % (n, R[rs], R[rt], s16(imm) << 2)
        if n in ("blez", "bgtz"):
            return "%-5s %s,%+d" % (n, R[rs], s16(imm) << 2)
        if n == "lui":
            return "%-5s %s,0x%x" % (n, R[rt], imm)
        if n in ("addi", "addiu", "slti", "sltiu", "andi", "ori", "xori"):
            if n in ("andi", "ori", "xori"):
                return "%-5s %s,%s,0x%x" % (n, R[rt], R[rs], imm)
            return "%-5s %s,%s,%d" % (n, R[rt], R[rs], s16(imm))
        return "%-5s %s,%d(%s)" % (n, R[rt], s16(imm), R[rs])
    return "op?0x%02x" % op


def words(hexstr):
    b = bytes.fromhex(hexstr)
    out = []
    for i in range(0, len(b), 4):
        out.append(int.from_bytes(b[i:i + 4], "little"))
    return out


if __name__ == "__main__":
    tgt = sys.argv[1] if len(sys.argv) > 1 else "analysis/final-mix/worker-coordination/worker-b/round-4/targets.json"
    rows = json.load(open(tgt))
    if isinstance(rows, dict):
        rows = rows.get("targets", rows)
    for t in rows:
        addr = t["address"]
        print("=" * 70)
        print("%s  size=%s  differing=%s" % (addr, t.get("size"), t.get("difference_offsets")))
        tw = words(t["original_hex"])
        cw = words(t["compiled_hex"])
        diff = set(t.get("difference_offsets") or [])
        for i in range(max(len(tw), len(cw))):
            a = tw[i] if i < len(tw) else None
            b = cw[i] if i < len(cw) else None
            mark = "*" if i * 4 in diff or (a != b) else " "
            print("%s %3d T %08x %-26s C %08x %s" % (
                mark, i * 4,
                a or 0, dec(a) if a is not None else "-",
                b or 0, dec(b) if b is not None else "-"))