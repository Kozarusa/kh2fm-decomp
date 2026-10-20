#!/usr/bin/env python3
"""Worker B: source variants for the remaining initializer targets.

Follow-up to the 001c8e00 finding: the archived draft's nested guards plus
asm barriers are what break equivalence; plain flat guards reproduce the
original instruction stream. Each variant here is a flat, barrier-free
restatement.
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
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
extern u8 D_0032b930, D_01d498d0, D_01c620c8[];
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern "C" void func_0031b9e0(void*);
"""

VARIANTS = {
    "w01_161410_flat": """
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
}
""",
    "w02_1ba060_flat": """
void func_001ba060(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_01d48da0.first = 0; D_01d48da0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48da8.first = 0; D_01d48da8.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db0.first = 0; D_01d48db0.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_01d48db8 = 0; }
}
""",
    "w03_1c7ab8_flat": """
void func_001c7ab8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_01d498c0 = D_0036dfd4;
    if (priority == 0xffffu && phase == 1) D_01d498c4 = D_0036dfd8;
    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);
}
""",
    "w04_1d6850_flat": """
void func_001d6850(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = D_0036e5ec;
    }
    if (priority == 0xffffu && phase == 1) {
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = D_0036e5f0;
    }
}
""",
    "w05_1995f8_flat": """
void func_001995f8(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* target = (u32*)(D_01c620c8 + 0x60);
        u32 index;
        for (index = 0; index < 4; ++index) *target++ = index;
        *(u32*)(D_01c620c8 + 0x70) = 4;
    }
    if (priority == 0xffffu && phase == 1) { D_01c62140.first = 0; D_01c62140.second = 0; }
}
""",
    "w06_241f20_flat": """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32* target = D_01dae688;
        target[4] = 0;
        target[1] = 0x3c4;
        target[0] = D_0035ebf8;
        target[2] = D_0035ebfc;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
""",
    # 00104210: flat value clamping. Registers are left to the compiler first;
    # later variants pin them once the plain shape is known.
    "w07_104210_plain": """
extern u32 D_0032ba84;
extern "C" void func_00104200(u32);

void func_00104210(s32 value) {
    D_0032ba84 = (0 < value) ? 1u : (u32)value;
    if (D_0032ba84 == 2u) { func_00104200(2u); return; }
    if (D_0032ba84 < 3u) { if (D_0032ba84 != 1u) func_00104200(2u); return; }
    if (D_0032ba84 != 3u) return;
    func_00104200(3u);
}
""",
}

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(VARIANTS.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(VARIANTS)))