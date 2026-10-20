#!/usr/bin/env python3
"""Worker B: fifth generation of variants, driven by exact diffs.

Confirmed gaps and hypotheses:
  001d6850 - target keeps the two guard constants LIVE across both blocks
             (`ori $t4,$0,0xffff` and `li $t3,1` emitted once at function top),
             which frees $14/$15 for the address pair.  Flat guards re-materialise
             0xffff in $t7 and the pair lands as ($14=page,$15=full) instead of
             ($15=page,$14=full).
  001c7ab8 - only the prologue words differ: target keeps `sd ra,0($sp)` BEFORE
             the first `bne`; the probe sinks it into the delay slot.
  00241f20 - store order is right with barriers, but target loads the FIRST global
             early into $t2 and the second into $t3 (both live simultaneously).
  00104210 - `positive` must genuinely occupy $15 (currently recomputed in $a0).
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

BODY = {}

# ---------------------------------------------------------------- 001d6850
def d6850(name, mask_decl, one_decl, pin_mask=None, pin_one=None):
    pre = ""
    if pin_mask:
        pre += f'    register u32 mask asm("${pin_mask}") = 0xffffu;\n'
        pre += '    asm("" : "+r"(mask));\n'
    if pin_one:
        pre += f'    register u32 one asm("${pin_one}") = 1u;\n'
        pre += '    asm("" : "+r"(one));\n'
    BODY[name] = f"""
void func_001d6850(u32 phase, u32 priority) {{
{mask_decl}{one_decl}{pre}    if (priority == {"mask" if mask_decl else "0xffffu"} && phase == {"one" if one_decl else "1u"}) {{
        register f32* source asm("$13") = &D_0036e5ec;
        asm("" : "+r"(source));
        D_01d5ba78.first = 0; D_01d5ba78.second = 0; D_01d5ba78.value = *source;
    }}
    if (priority == {"mask" if mask_decl else "0xffffu"} && phase == {"one" if one_decl else "1u"}) {{
        register f32* source asm("$15") = &D_0036e5f0;
        asm("" : "+r"(source));
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }}
}}
"""

d6850("s01_1d6850_maskone", "u32 mask = 0xffffu;\n", "u32 one = 1u;\n")
d6850("s02_1d6850_mask12_11", "", "", pin_mask="12", pin_one="11")
d6850("s03_1d6850_mask14_one15", "", "", pin_mask="14", pin_one="15")
d6850("s04_1d6850_maskone_opaque", "u32 mask = 0xffffu;\n", "u32 one = 1u;\n")

# ---------------------------------------------------------------- 001c7ab8
def c7ab8(name, top_asm=False, post_call_asm=True, volatile_dst=False):
    pre = '    asm volatile("" ::: "memory");\n' if top_asm else ""
    post = '    asm volatile("" ::: "memory");\n' if post_call_asm else ""
    d0 = "volatile " if volatile_dst else ""
    BODY[name] = f"""
void func_001c7ab8(u32 phase, u32 priority) {{
{pre}    if (priority == 0xffffu && phase == 1) {{
        register f32* source asm("$15") = &D_0036dfd4;
        asm("" : "+r"(source));
        {d0}f32* dst = &D_01d498c0;
        asm("" : "+r"(dst));
        *dst = *source;
    }}
    if (priority == 0xffffu && phase == 1) {{
        register f32* source asm("$15") = &D_0036dfd8;
        asm("" : "+r"(source));
        {d0}f32* dst = &D_01d498c4;
        asm("" : "+r"(dst));
        *dst = *source;
    }}
    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);
{post}}}
"""

c7ab8("s05_1c7ab8_topasm", top_asm=True)
c7ab8("s06_1c7ab8_nopost", top_asm=False, post_call_asm=False)
c7ab8("s07_1c7ab8_tops", top_asm=True, post_call_asm=False)
c7ab8("s08_1c7ab8_voldst", volatile_dst=True)
c7ab8("s09_1c7ab8_topasm_vol", top_asm=True, volatile_dst=True)

# ---------------------------------------------------------------- 00241f20
BODY["s10_241f20_srcorder"] = """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32 first = D_0035ebf8;
        u32* target = D_01dae688;
        target[4] = 0;
        target[1] = 0x3c4;
        target[0] = first;
        u32 second = D_0035ebfc;
        target[2] = second;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
"""

BODY["s11_241f20_twobar"] = """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32 first = D_0035ebf8;
        u32 second = D_0035ebfc;
        u32* target = D_01dae688;
        target[4] = 0;
        target[1] = 0x3c4;
        target[0] = first;
        target[2] = second;
        target[3] = 0x8a58;
        target[5] = 0x00010000u | 0xfc0u;
    }
}
"""

BODY["s12_241f20_constregs"] = """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32 first = D_0035ebf8;
        u32 second = D_0035ebfc;
        register u32 flag asm("$14") = 0x3c4u;
        register u32 extra asm("$15") = 0x00010000u | 0xfc0u;
        asm("" : "+r"(flag), "+r"(extra));
        u32* target = D_01dae688;
        target[4] = 0;
        target[1] = flag;
        target[0] = first;
        target[2] = second;
        target[3] = 0x8a58;
        target[5] = extra;
    }
}
"""

BODY["s13_241f20_ptrsplit"] = """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        u32 first = D_0035ebf8;
        register u32* base asm("$13") = D_01dae688;
        asm("" : "+r"(base));
        base[4] = 0;
        base[1] = 0x3c4;
        base[0] = first;
        u32 second = D_0035ebfc;
        base[2] = second;
        base[3] = 0x8a58;
        base[5] = 0x00010000u | 0xfc0u;
    }
}
"""

# ---------------------------------------------------------------- 00104210
BODY["s14_104210_pin15"] = """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
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
"""

BODY["s15_104210_pin15_goto"] = """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
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
"""

BODY["s16_104210_swapargs"] = """
void func_00104210(s32 value) {
    register s32 current asm("$14") = value;
    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
    D_0032ba84 = current;
    if (current == 2) { func_00104200(selected); return; }
    if (current >= 3) {
        if (current != 3) return;
        selected = 3;
        func_00104200(selected);
        return;
    }
    if (current != 1) { func_00104200(selected); return; }
    selected = 1;
}
"""

BODY["s17_104210_nopins"] = """
void func_00104210(s32 value) {
    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
    D_0032ba84 = current;
    if (current == 2) { func_00104200(selected); return; }
    if (current >= 3) {
        if (current == 3) { selected = 3; func_00104200(selected); }
        return;
    }
    if (current != 1) { func_00104200(selected); return; }
    selected = 1;
}
"""

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))