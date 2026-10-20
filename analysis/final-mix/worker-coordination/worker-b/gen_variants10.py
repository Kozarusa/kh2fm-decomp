#!/usr/bin/env python3
"""Worker B: targeted grids for the three register/scheduling residuals.

Each grid attacks ONE named cause that the word-level diff pinned down:

  001d6850  the destination address pair is allocated base-high/index-low in
            the target (`lui t7,0x1d6` / `addiu t6,t7,-17800`) and
            base-low/index-high in every probe.  Grid: source-register pin x
            field-store order x destination access style.

  00241f20  the target keeps the two loaded globals in $t2/$t3 (long live
            ranges) and materialises `li $t6,964` early.  Grid: hoisting
            position of each load x store-ordering mechanism x barrier subsets.

  001c7ab8  two single-word defects: `li $t7,0xffff` must precede `sd ra`, and
            the third guard's `bne` delay slot must stay `nop`.  Grid: barrier
            placement x argument-passing style x volatile destinations.
"""
import itertools
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."
BODY = {}

# ---------------------------------------------------------------- 001d6850
PRE68 = """typedef unsigned int u32;
typedef float f32;
extern f32 D_0036e5ec, D_0036e5f0;
struct S { u32 a; u32 b; f32 c; } D_01d5ba78, D_01d5ba88;
"""
HEAD68 = ("void func_001d6850(u32 phase, u32 priority) {\n"
          "    if (priority == 0xffffu && phase == 1) {\n")
FIELDS = ["D_01d5ba78.a = 0;", "D_01d5ba78.b = 0;",
          "D_01d5ba78.c = *%s;"]


def block68(dest, order, srcvar):
    body = []
    for i in order:
        body.append(FIELDS[i] % srcvar)
    return "        " + "\n        ".join(body)


for order in itertools.permutations(range(3)):
    for style in ("struct", "ptr"):
        for pin in ("13", "none", "15"):
            if style == "struct":
                d1 = "D_01d5ba78"
            else:
                d1 = "(u32*)0x01d5ba78"
            if pin == "none":
                decl = ""
            else:
                decl = ('        register f32* src asm("$%s") = &D_0036e5ec;\n'
                        '        asm("" : "+r"(src));\n' % pin)
                first = "*src"
            first = ("*src" if pin != "none"
                     else ("D_0036e5ec" if style == "struct" else "*(f32*)0x0036e5ec"))
            if style == "struct":
                lines = ["D_01d5ba78.a = 0;", "D_01d5ba78.b = 0;",
                         "D_01d5ba78.c = %s;" % first]
            else:
                lines = ["((u32*)0x01d5ba78)[0] = 0;",
                         "((u32*)0x01d5ba78)[1] = 0;",
                         "*((f32*)0x01d5ba78 + 2) = %s;" % first]
            b1 = "        " + "\n        ".join(lines[i] for i in order)
            decl2 = ('        register f32* src2 asm("$15") = &D_0036e5f0;\n'
                     '        asm("" : "+r"(src2));\n')
            first2 = ("*src2" if pin != "none" else
                      ("D_0036e5f0" if style == "struct" else "*(f32*)0x0036e5f0"))
            if style == "struct":
                lines2 = ["D_01d5ba88.a = 3;", "D_01d5ba88.b = 0;",
                          "D_01d5ba88.c = %s;" % first2]
            else:
                lines2 = ["((u32*)0x01d5ba88)[0] = 3;",
                          "((u32*)0x01d5ba88)[1] = 0;",
                          "*((f32*)0x01d5ba88 + 2) = %s;" % first2]
            b2 = "        " + "\n        ".join(lines2)
            name = "c_%s_%s_pin%s_1d6850" % (style, "".join(map(str, order)), pin)
            BODY[name] = (PRE68 + HEAD68 + decl + b1 + "\n    }\n"
                          "    if (priority == 0xffffu && phase == 1) {\n"
                          + decl2 + b2 + "\n    }\n}\n")

# ---------------------------------------------------------------- 00241f20
PRE20 = """typedef unsigned int u32;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
"""
HEAD20 = ("void func_00241f20(u32 phase, u32 priority) {\n"
          "    if (priority == 0xffffu && phase == 1) {\n")
STORES = ["base[4] = 0;", "base[1] = 0x3c4;", "base[0] = first;",
          "base[2] = second;", "base[3] = 0x8a58;",
          "base[5] = 0x00010000u | 0xfc0u;"]
BAR = 'asm volatile("" ::: "memory");'

for hoist_first in (0, 1):
    for hoist_second in (0, 1):
        for mech in ("plain", "bar", "volatile"):
            for bsize in ((0,) if mech != "bar" else (1, 2)):
                seq = []
                for i, s in enumerate(STORES):
                    if i == 0 and hoist_first:
                        seq.append("u32 first = D_0035ebf8;")
                    if i == 3 and hoist_second:
                        seq.append("u32 second = D_0035ebfc;")
                    seq.append(s)
                if not hoist_first:
                    seq.insert(0, "u32 first = D_0035ebf8;")
                if not hoist_second:
                    seq.insert(seq.index("base[2] = second;"), "u32 second = D_0035ebfc;")
                if mech == "bar":
                    idx = ([1, 2, 3, 4, 5] if bsize == 1
                           else list(itertools.combinations(range(1, 7), 2)))
                    marks = set()
                    for combo in (idx if bsize == 1 else idx):
                        if bsize == 1:
                            marks.add(combo)
                        else:
                            marks |= set(combo)
                    for i in range(len(seq)):
                        if i in marks:
                            seq.insert(i, BAR)
                decl = "volatile u32* base = D_01dae688;" if mech == "volatile" \
                    else "u32* base = D_01dae688;"
                body = ("        " + decl + "\n        " + "\n        ".join(seq) + "\n")
                name = "d_h%d%d_%s_b%d_241f20" % (hoist_first, hoist_second,
                                                  mech, bsize)
                BODY[name] = PRE20 + HEAD20 + body + "    }\n}\n"

# ---------------------------------------------------------------- 001c7ab8
PREAB = """typedef unsigned int u32;
typedef float f32;
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern u32 D_01d498d0;
extern "C" void func_0031b9e0(void*);
"""
HEADAB = ("void func_001c7ab8(u32 phase, u32 priority) {\n")
COPY1 = "        D_01d498c0 = *src;"
COPY2 = "        D_01d498c4 = *src;"
DECL = ('        register f32* src asm("$15") = &%s;\n'
        '        asm("" : "+r"(src));\n')
BAR = '    asm volatile("" ::: "memory");\n'

for pin in ("15", "13", "none"):
    for barpos in ("none", "top", "after1", "after2", "beforecall", "all"):
        for vol in (False, True):
            src1 = ("*src" if pin != "none" else "D_0036dfd4")
            src2 = ("*src" if pin != "none" else "D_0036dfd8")
            decl = (DECL % "D_0036dfd4") if pin != "none" else ""
            decl2 = (DECL % "D_0036dfd8") if pin != "none" else ""
            t1 = "volatile f32 d1 = D_01d498c0;\n        d1 = %s;\n" % src1 if vol \
                else "        D_01d498c0 = %s;\n" % src1
            t2 = "volatile f32 d2 = D_01d498c4;\n        d2 = %s;\n" % src2 if vol \
                else "        D_01d498c4 = %s;\n" % src2
            b1 = "    if (priority == 0xffffu && phase == 1) {\n" + decl + t1 + "    }\n"
            b2 = "    if (priority == 0xffffu && phase == 1) {\n" + decl2 + t2 + "    }\n"
            b3 = ("    if (priority == 0xffffu && phase == 1) {\n"
                  "        func_0031b9e0(&D_01d498d0);\n    }\n")
            parts = {"top": BAR + b1 + b2 + b3,
                     "after1": b1 + BAR + b2 + b3,
                     "after2": b1 + b2 + BAR + b3,
                     "beforecall": b1 + b2 + BAR + b3,
                     "all": BAR + b1 + BAR + b2 + BAR + b3,
                     "none": b1 + b2 + b3}[barpos]
            name = "e_pin%s_%s_%s_1c7ab8" % (pin, barpos, "v" if vol else "n")
            BODY[name] = PREAB + HEADAB + parts + "}\n"

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(body)
print(len(BODY), "variants written to", WORK)