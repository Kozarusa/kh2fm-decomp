#!/usr/bin/env python3
"""Worker B: second targeted grid for 001d6850's address-pair direction.

The diff shows the target allocates the destination pair base-high/index-low
(`lui $t7,0x1d6` / `addiu $t6,t7,-17800`) while every probe gets
base-low/index-high.  Field order, source pin and access style did not move it
(36 variants).  Two untried levers:

  * the RTL shape of the address expression, which decides whether the constant
    or the register is operand 0 of the `plus` the reload splits;
  * the number of registers already allocated when the pair is allocated, by
    adding one extra live value at a chosen register.
"""
import itertools
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."
PRE = """typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern f32 D_0036e5ec, D_0036e5f0;
struct S { u32 a; u32 b; f32 c; } D_01d5ba78, D_01d5ba88;
"""
HEAD = ("void func_001d6850(u32 phase, u32 priority) {\n"
        "    if (priority == 0xffffu && phase == 1) {\n")

# Four ways to spell the destination store, all semantically identical.
STYLES = {
    "struct": ("D_01d5ba78.a = 0;\n        D_01d5ba78.b = 0;\n"
               "        D_01d5ba78.c = *src;"),
    "u8base": ("u8* p = (u8*)&D_01d5ba78;\n"
               "        *(u32*)p = 0;\n"
               "        *(u32*)(p + 4) = 0;\n"
               "        *(f32*)(p + 8) = *src;"),
    "plus0": ("*(u32*)((u8*)&D_01d5ba78 + 0) = 0;\n"
              "        *(u32*)((u8*)&D_01d5ba78 + 4) = 0;\n"
              "        *(f32*)((u8*)&D_01d5ba78 + 8) = *src;"),
    "arridx": ("u32* p = (u32*)&D_01d5ba78;\n"
               "        p[0] = 0;\n"
               "        p[1] = 0;\n"
               "        ((f32*)p)[2] = *src;"),
}
STYLES2 = {
    "struct": ("D_01d5ba88.a = 3;\n        D_01d5ba88.b = 0;\n"
               "        D_01d5ba88.c = *src;"),
    "u8base": ("u8* p = (u8*)&D_01d5ba88;\n"
               "        *(u32*)p = 3;\n"
               "        *(u32*)(p + 4) = 0;\n"
               "        *(f32*)(p + 8) = *src;"),
    "plus0": ("*(u32*)((u8*)&D_01d5ba88 + 0) = 3;\n"
              "        *(u32*)((u8*)&D_01d5ba88 + 4) = 0;\n"
              "        *(f32*)((u8*)&D_01d5ba88 + 8) = *src;"),
    "arridx": ("u32* p = (u32*)&D_01d5ba88;\n"
               "        p[0] = 3;\n"
               "        p[1] = 0;\n"
               "        ((f32*)p)[2] = *src;"),
}
DECL = ('        register f32* src asm("$%s") = &%s;\n'
        '        asm("" : "+r"(src));\n')

BODY = {}
for style in STYLES:
    for pin, extra in itertools.product(("13", "12", "none"),
                                        (None, "$14", "$12", "$15", "$30")):
        d1 = DECL % (pin, "D_0036e5ec") if pin != "none" else ""
        d2 = DECL % ("15", "D_0036e5f0")
        first = "*src" if pin != "none" else "D_0036e5ec"
        first2 = "*src"
        b1 = STYLES[style].replace("*src", first)
        b2 = STYLES2[style].replace("*src", first2)
        pre = ""
        if extra:
            pre = ('        register u32 keep asm("%s") = (u32)&D_0036e5f0;\n'
                   '        asm("" : "+r"(keep));\n' % extra)
        tag = "none" if extra is None else extra.replace("$", "")
        BODY["g_%s_pin%s_x%s_1d6850" % (style, pin, tag)] = (
            PRE + HEAD + pre + d1 + "        " + b1 + "\n    }\n"
            "    if (priority == 0xffffu && phase == 1) {\n"
            + d2 + "        " + b2 + "\n    }\n}\n")

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(body)
print(len(BODY), "variants written to", WORK)