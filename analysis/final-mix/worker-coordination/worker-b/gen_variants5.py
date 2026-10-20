#!/usr/bin/env python3
"""Worker B: fourth generation of variants, driven by the near-miss diffs.

Remaining gaps at this point:
  001d6850 - dest page/full registers swapped ($15/$14 vs $14/$15)
  001c7ab8 - `sd ra,0(sp)` scheduled after instead of before the first branch
  00241f20 - store order and load/store interleaving
  00104210 - missing `li $a0,1`, branch-likely forms, `one` must live in $12
"""
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."

PRE = """typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;
struct FmInitPair { u32 first, second; };
struct FmInitFloat { u32 first, second; f32 value; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48, D_01c62140;
extern FmInitPair D_01d48da0, D_01d48da8, D_01d48db0;
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01d48db8, D_00351eb8, D_00351ec0, D_00351ec8;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc, D_0032ba84;
extern u8 D_0032b930, D_01d498d0, D_01c620c8[];
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00104200(u32);
"""

D6850_HEAD = """
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$13") = &D_0036e5ec;
        asm("" : "+r"(source));
"""
D6850_TAIL = """
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036e5f0;
        asm("" : "+r"(source));
        D_01d5ba88.%s = %s; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }
}
"""

BODY = {
    # ---- 001d6850 : permute the three field stores in each block ---------
    "z01_1d6850_fsv": D6850_HEAD +
        "        D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = *source;\n"
        "    }\n" + D6850_TAIL % ("first", "3"),
    "z02_1d6850_vfs": D6850_HEAD +
        "        D_01d5ba78.value = *source; D_01d5ba78.first = 0; D_01d5ba78.second = 0;\n"
        "    }\n" + D6850_TAIL % ("first", "3"),
    "z03_1d6850_sfv": D6850_HEAD +
        "        D_01d5ba78.second = 0; D_01d5ba78.first = 0; D_01d5ba78.value = *source;\n"
        "    }\n" + D6850_TAIL % ("first", "3"),
    "z04_1d6850_svf": D6850_HEAD +
        "        D_01d5ba78.second = 0; D_01d5ba78.value = *source; D_01d5ba78.first = 0;\n"
        "    }\n" + D6850_TAIL % ("first", "3"),
    # ---- 001c7ab8 -------------------------------------------------------
    "z05_1c7ab8_nobar": """
void func_001c7ab8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036dfd4;
        asm("" : "+r"(source));
        D_01d498c0 = *source;
    }
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036dfd8;
        asm("" : "+r"(source));
        D_01d498c4 = *source;
    }
    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);
}
""",
    # ---- 00241f20 -------------------------------------------------------
    "z06_241f20_hoist": """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* target = D_01dae688;
        u32 first = D_0035ebf8;
        u32 second = D_0035ebfc;
        target[4] = 0;
        target[1] = 0x3c4;
        target[0] = first;
        target[2] = second;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
""",
    "z07_241f20_hoist_interleave": """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* target = D_01dae688;
        u32 first = D_0035ebf8;
        target[4] = 0;
        asm volatile("" ::: "memory");
        target[1] = 0x3c4;
        asm volatile("" ::: "memory");
        target[0] = first;
        u32 second = D_0035ebfc;
        target[2] = second;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
""",
    # ---- 00104210 -------------------------------------------------------
    "z08_104210_pinned": """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    D_0032ba84 = current;
    if (current == 2) { func_00104200(selected); return; }
    if (current < 3) {
        if (current != 1) { func_00104200(selected); return; }
        selected = 1;
        return;
    }
    if (current != 3) return;
    selected = 3;
    func_00104200(selected);
}
""",
    "z09_104210_goto": """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    D_0032ba84 = current;
    if (current == 2) goto tail;
    if (current >= 3) {
        if (current != 3) return;
        selected = 3;
        goto tail;
    }
    if (current != 1) goto tail;
    selected = 1;
    return;
tail:
    func_00104200(selected);
}
""",
    "z10_104210_nostore1": """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    D_0032ba84 = current;
    if (current == 2) { func_00104200(selected); return; }
    if (current < 3) {
        if (current == 1) { selected = 1; return; }
        func_00104200(selected);
        return;
    }
    if (current != 3) return;
    selected = 3;
    func_00104200(selected);
}
""",
}

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))