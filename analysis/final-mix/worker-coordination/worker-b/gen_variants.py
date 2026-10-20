#!/usr/bin/env python3
"""Worker B: generate source variants for the eight initializer targets and
probe each one with the pinned toolchain (probe_fm_source.py).

Usage:
    python3 gen_variants.py <workdir>
Writes <workdir>/v<NN>_<name>.cpp for every variant and prints the file list.
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
extern u32 D_00351eb8, D_00351ec0, D_00351ec8;
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48;
extern FmInitFloat D_01d5ba78, D_01d5ba88;
extern u32 D_01d48db8;
extern f32 D_0036dfd4, D_0036dfd8, D_01d498c0, D_01d498c4;
extern f32 D_0036e5ec, D_0036e5f0;
extern u8 D_0032b930, D_01d498d0, D_0033cb80[], D_01c620c8[];
extern u32 D_01dae688[6], D_0032ba84, D_0035ebf8, D_0035ebfc;
extern "C" void func_0031b9e0(void*);
extern "C" void func_00104200(u32);
"""

VARIANTS = {
    # --- 001c8e00 : three flat guarded stores of zero -------------------
    "v01_c8e00_flat_noasm": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v02_c8e00_flat_both_rw": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(phase), "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v03_c8e00_flat_memory": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" ::: "memory");
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" ::: "memory");
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v04_c8e00_flat_prio_only": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v05_c8e00_flat_prio_in_out": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(priority) : "r"(phase));
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(priority) : "r"(phase));
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v06_c8e00_flat_phase_only": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(phase) : "r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(phase) : "r"(priority));
        if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v07_c8e00_three_flat_guards": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) D_00351eb8 = 0;
    if (priority == 0xffffu && phase == 1) D_00351ec0 = 0;
    if (priority == 0xffffu && phase == 1) D_00351ec8 = 0;
}
""",
    "v08_c8e00_nested_noasm": """
void func_001c8e00(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) D_00351eb8 = 0;
        else { }
        if (priority == 0xffffu) { if (phase == 1) D_00351ec0 = 0; }
        if (priority == 0xffffu) { if (phase == 1) D_00351ec8 = 0; }
    }
}
""",
    "v09_c8e00_regvar_magic": """
void func_001c8e00(u32 phase, u32 priority) {
    register u32 magic asm("$15") = 0xffffu;
    if (priority == magic) {
        if (phase == 1) D_00351eb8 = 0;
        magic = 0xffffu;
        if (priority == magic && phase == 1) D_00351ec0 = 0;
        magic = 0xffffu;
        if (priority == magic && phase == 1) D_00351ec8 = 0;
    }
}
""",
    "v10_c8e00_shadow_locals": """
void func_001c8e00(u32 phase, u32 priority) {
    u32 p = priority, q = phase;
    if (p == 0xffffu) {
        if (q == 1) D_00351eb8 = 0;
        asm volatile("" : "+r"(p), "+r"(q));
        if (p == 0xffffu && q == 1) D_00351ec0 = 0;
        asm volatile("" : "+r"(p), "+r"(q));
        if (p == 0xffffu && q == 1) D_00351ec8 = 0;
    }
}
""",
}

os.makedirs(WORK, exist_ok=True)
names = []
for name, body in sorted(VARIANTS.items()):
    path = os.path.join(WORK, name + ".cpp")
    with open(path, "w", newline="\n") as fh:
        fh.write(PRE + body)
    names.append(path)
print("\n".join(names))