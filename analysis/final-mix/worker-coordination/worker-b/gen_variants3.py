#!/usr/bin/env python3
"""Worker B: shape variants for the paired-store initializer shape.

Target pattern (00161410 block 1):
    li    t7,0xffff
    lui   t6,0x4f          <- page in $14
    addiu t7,t6,0x3b38     <- full address in $15
    sw    zero,0x3b38(t6)
    sw    zero,4(t7)
"""
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."

PRE = """typedef unsigned int u32;
typedef unsigned char u8;
struct FmInitPair { u32 first, second; };
extern FmInitPair D_004f3b38, D_004f3b40, D_004f3b48;
extern u32 D_004f3b38_raw[2];
extern "C" u32 sink_reg;
"""

BODY = {
    # store order swapped
    "x01_swap_fields": """
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_004f3b38.second = 0; D_004f3b38.first = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b40.second = 0; D_004f3b40.first = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b48.second = 0; D_004f3b48.first = 0; }
}
""",
    # through a local pointer variable
    "x02_pointer": """
void func_00161410(u32 phase, u32 priority) {
    u32* p = (u32*)&D_004f3b38.first;
    u32* q = (u32*)&D_004f3b40.first;
    u32* r = (u32*)&D_004f3b48.first;
    if (priority == 0xffffu && phase == 1) { p[0] = 0; p[1] = 0; }
    if (priority == 0xffffu && phase == 1) { q[0] = 0; q[1] = 0; }
    if (priority == 0xffffu && phase == 1) { r[0] = 0; r[1] = 0; }
}
""",
    # whole-struct assignment from a zeroed temporary
    "x03_struct_assign": """
void func_00161410(u32 phase, u32 priority) {
    FmInitPair zero;
    zero.first = 0;
    zero.second = 0;
    if (priority == 0xffffu && phase == 1) D_004f3b38 = zero;
    if (priority == 0xffffu && phase == 1) D_004f3b40 = zero;
    if (priority == 0xffffu && phase == 1) D_004f3b48 = zero;
}
""",
    # raw u32[2] indexing
    "x04_raw_array": """
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) { D_004f3b38_raw[0] = 0; D_004f3b38_raw[1] = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b38_raw[2] = 0; D_004f3b38_raw[3] = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b38_raw[4] = 0; D_004f3b38_raw[5] = 0; }
}
""",
    # zero through a pointer held in a register variable
    "x05_regvar_page": """
void func_00161410(u32 phase, u32 priority) {
    register u32 page asm("$14") = 0x004f0000u;
    if (priority == 0xffffu && phase == 1) {
        asm volatile("" : "+r"(page));
        D_004f3b38.first = 0;
        D_004f3b38.second = 0;
    }
    if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
    if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
}
""",
    # guard expressed as nested pair of ifs (draft-like) but without asm
    "x06_nested_noasm": """
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu) {
        if (phase == 1) { D_004f3b38.first = 0; D_004f3b38.second = 0; }
        if (priority == 0xffffu && phase == 1) { D_004f3b40.first = 0; D_004f3b40.second = 0; }
        if (priority == 0xffffu && phase == 1) { D_004f3b48.first = 0; D_004f3b48.second = 0; }
    }
}
""",
    # stores written as a single 64-bit value
    "x07_u64_store": """
void func_00161410(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        *(volatile u64*)&D_004f3b38.first = 0;
        *(volatile u64*)&D_004f3b40.first = 0;
        *(volatile u64*)&D_004f3b48.first = 0;
    }
}
""",
}

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))