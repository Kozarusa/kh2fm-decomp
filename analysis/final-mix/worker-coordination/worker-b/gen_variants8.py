#!/usr/bin/env python3
"""Worker B: seventh generation - last targeted grid.

001c7ab8 - need `sd ra,0($sp)` between `li $t7,0xffff` and the first `bne`.
           The delay-slot filler steals it unless the prologue cannot be moved;
           opaque input operands are tried next to the memory barrier.
001d6850 - block1 body matches instruction-for-instruction except that GCC
           allocates the address pair as ($t6=page,$t7=full) instead of
           ($t7=page,$t6=full); source-pointer pinning and store order are the
           only levers left.
00241f20 - the store order needs memory barriers, but the barriers must not
           force each load/store pair together: barrier subsets are enumerated.
"""
import itertools
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."

PRE = """typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;
struct FmInitFloat { u32 first, second; f32 value; };
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
extern u8 D_01d498d0;
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00104200(u32);
extern u32 D_0032ba84;
"""

BODY = {}

# ------------------------------------------------------------------ 001c7ab8
COPYS = """    if (priority == 0xffffu && phase == 1) {{
        register f32* source asm("$15") = &{src};
        asm("" : "+r"(source));
        {dst} = *source;
    }}
"""
HEADS = {
    "plain": "",
    "mem": '    asm volatile("" ::: "memory");\n',
    "inp": '    asm volatile("" : "+r"(phase), "+r"(priority));\n',
    "meminp": ('    asm volatile("" ::: "memory");\n'
               '    asm volatile("" : "+r"(phase), "+r"(priority));\n'),
    "ra": '    register void* saved asm("$30") = 0;\n    asm volatile("" : "+r"(saved));\n',
    "memra": ('    asm volatile("" ::: "memory");\n'
              '    register void* saved asm("$30") = 0;\n'
              '    asm volatile("" : "+r"(saved));\n'),
}
for htag, head in HEADS.items():
    for dtag, dst in (("plain", "D_01d498c0"), ("vol", "*(volatile f32*)&D_01d498c0")):
        pass
    BODY[f"x_{htag}_1c7ab8"] = (
        "void func_001c7ab8(u32 phase, u32 priority) {\n" + head
        + COPYS.format(src="D_0036dfd4", dst="D_01d498c0")
        + COPYS.format(src="D_0036dfd8", dst="D_01d498c4")
        + "    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);\n"
        + '    asm volatile("" ::: "memory");\n}\n')

# ------------------------------------------------------------------ 001d6850
def block(field_order, value_src):
    return " ".join(f"D_01d5ba7X.{f} = " + (value_src if f == "value" else "0") + ";"
                    for f in field_order)

for p1 in ("none", "13"):
    for p2 in ("none", "15"):
        for order in (("first", "second", "value"),
                      ("first", "value", "second"),
                      ("value", "first", "second")):
            tag = p1 + p2 + "".join(f[0] for f in order)
            src1 = ('        register f32* source asm("$13") = &D_0036e5ec;\n'
                    '        asm("" : "+r"(source));\n' if p1 == "13"
                    else "        f32* source = &D_0036e5ec;\n")
            src2 = ('        register f32* source asm("$15") = &D_0036e5f0;\n'
                    '        asm("" : "+r"(source));\n' if p2 == "15"
                    else "        f32* source = &D_0036e5f0;\n")
            body1 = " ".join(
                f"D_01d5ba78.{f} = " + ("*source" if f == "value" else "0") + ";"
                for f in order)
            BODY[f"y_{tag}_1d6850"] = f"""
void func_001d6850(u32 phase, u32 priority) {{
    if (priority == 0xffffu && phase == 1) {{
{src1}        {body1}
    }}
    if (priority == 0xffffu && phase == 1) {{
{src2}        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }}
}}
"""

# ------------------------------------------------------------------ 00241f20
def f24120(barriers):
    lines = ['        u32 first = D_0035ebf8;', "        base[4] = 0;"]
    for i, stmt in enumerate(("        base[1] = 0x3c4;",
                              "        base[0] = first;",
                              "        base[2] = D_0035ebfc;",
                              "        base[3] = 0x8a58;",
                              "        base[5] = 0x00010000u | 0xfc0u;")):
        if i in barriers:
            lines.append('        asm volatile("" ::: "memory");')
        lines.append(stmt)
    if 5 in barriers:
        lines.append('        asm volatile("" ::: "memory");')
    return "\n".join(lines) + "\n"

SUBSETS = [(0, 1, 2, 3), (0, 1, 2), (0, 1), (0, 2, 3), (1, 2, 3), (0, 1, 3),
           (0, 1, 2, 3, 4), (0, 2), (1, 2), (0, 1, 2, 3, 4, 5)]
for sub in SUBSETS:
    tag = "".join(str(i) for i in sub)
    BODY[f"z_bar{tag}_241f20"] = ("void func_00241f20(u32 phase, u32 priority) {\n"
        "    if (priority == 0xffffu && phase == 1) {\n"
        "        register u32* base asm(\"$12\") = D_01dae688;\n"
        '        asm("" : "+r"(base));\n' + f24120(set(sub)) + "    }\n}\n")

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))