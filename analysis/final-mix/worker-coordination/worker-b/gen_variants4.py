#!/usr/bin/env python3
"""Worker B: third generation of variants, applying the two lessons from the
matches so far:

1. flat, barrier-free guards reproduce the repeated priority/phase compares;
2. an address that the original materializes into a register (rather than
   folding into reg+offset) comes from a `register ... asm("$nn")` local.
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

BODY = {
    # ---- 001d6850 -------------------------------------------------------
    "y01_1d6850_regptr": """
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$13") = &D_0036e5ec;
        asm("" : "+r"(source));
        D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = *source;
    }
    if (priority == 0xffffu && phase == 1) {
        register f32* source asm("$15") = &D_0036e5f0;
        asm("" : "+r"(source));
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }
}
""",
    "y02_1d6850_plainptr": """
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        f32* source = &D_0036e5ec;
        D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = *source;
    }
    if (priority == 0xffffu && phase == 1) {
        f32* source = &D_0036e5f0;
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }
}
""",
    # ---- 001c7ab8 -------------------------------------------------------
    "y03_1c7ab8_regptr": """
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
    if (priority == 0xffffu && phase == 1) {
        func_0031b9e0(&D_01d498d0);
        asm volatile("" ::: "memory");
    }
}
""",
    "y04_1c7ab8_plainptr": """
void func_001c7ab8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_01d498c0 = D_0036dfd4; }
    if (priority == 0xffffu && phase == 1) { D_01d498c4 = D_0036dfd8; }
    if (priority == 0xffffu && phase == 1) { func_0031b9e0(&D_01d498d0); }
}
""",
    # ---- 001995f8 -------------------------------------------------------
    "y05_1995f8_base": """
void func_001995f8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u8* base = D_01c620c8;
        u32* target = (u32*)(base + 0x60);
        s32 index;
        for (index = 0; index < 4; ++index) *target++ = index;
        *(u32*)(base + 0x70) = 4;
    }
    if (priority == 0xffffu && phase == 1) { D_01c62140.first = 0; D_01c62140.second = 0; }
}
""",
    # ---- 00241f20 -------------------------------------------------------
    "y06_241f20_volatile": """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        volatile u32* target = D_01dae688;
        target[4] = 0;
        target[1] = 0x3c4;
        target[0] = D_0035ebf8;
        target[2] = D_0035ebfc;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
""",
    "y07_241f20_asmbar": """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* target = D_01dae688;
        target[4] = 0;
        asm volatile("" ::: "memory");
        target[1] = 0x3c4;
        asm volatile("" ::: "memory");
        target[0] = D_0035ebf8;
        asm volatile("" ::: "memory");
        target[2] = D_0035ebfc;
        asm volatile("" ::: "memory");
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
""",
    # ---- 00104210 -------------------------------------------------------
    "y08_104210_selected": """
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
    "y09_104210_terse": """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    D_0032ba84 = current;
    if (current != 2) {
        if (current < 3) {
            if (current != 1) { func_00104200(selected); return; }
            selected = 1;
            return;
        }
        else {
            if (current != 3) return;
            selected = 3;
        }
    }
    func_00104200(selected);
}
""",
}

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))