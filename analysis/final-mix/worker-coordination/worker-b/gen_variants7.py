#!/usr/bin/env python3
"""Worker B: sixth generation - targeted grid over the four remaining targets.

Authoritative target listings are now in hand, so each variant is aimed at a
single named difference.

001d6850  target block1 pair is ($t7 = page, $t6 = full); the probe emits
          ($t6 = page, $t7 = full).  Pinning the guard constants into $12/$11
          already fixed the code length, so the field-store order is permuted.
001c7ab8  only the prologue word order differs (`sd ra` must sit between
          `li $t7,0xffff` and the first `bne`), so barrier placement varies.
00241f20 the destination pointer must land in $t4 with page/full materialised,
          so the base pointer pin is varied.
00104210 `positive` must live in $t7 and the branch forms must not be
          branch-likely, so control-flow shapes are permuted.
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

# ------------------------------------------------------------------ 001d6850
for order in itertools.permutations(("first", "second", "value")):
    tag = "".join(w[0] for w in order)
    body1 = " ".join(
        f"D_01d5ba78.{f} = " + ("*source" if f == "value" else v) + ";"
        for f, v in zip(order, ("0", "0", "0")))
    BODY[f"t_{tag}_1d6850"] = f"""
void func_001d6850(u32 phase, u32 priority) {{
    register u32 mask asm("$12") = 0xffffu;
    register u32 one asm("$11") = 1u;
    asm("" : "+r"(mask), "+r"(one));
    if (priority == mask && phase == one) {{
        register f32* source asm("$13") = &D_0036e5ec;
        asm("" : "+r"(source));
        {body1}
    }}
    if (priority == mask && phase == one) {{
        register f32* source asm("$15") = &D_0036e5f0;
        asm("" : "+r"(source));
        D_01d5ba88.first = 3; D_01d5ba88.second = 0; D_01d5ba88.value = *source;
    }}
}}
"""

# ------------------------------------------------------------------ 001c7ab8
BARRIERS = {
    "none": "",
    "top": '    asm volatile("" ::: "memory");\n',
    "body": "",
    "both": '    asm volatile("" ::: "memory");\n',
}

for tag, top in (("none", ""), ("top", '    asm volatile("" ::: "memory");\n')):
    for ptag, post in (("post", '    asm volatile("" ::: "memory");\n'),
                       ("nopost", "")):
        for btag in ("none", "body"):
            inner_barrier = ('        asm volatile("" ::: "memory");\n' if btag == "body" else "")
            BODY[f"u_{tag}_{ptag}_{btag}_1c7ab8"] = f"""
void func_001c7ab8(u32 phase, u32 priority) {{
{top}    if (priority == 0xffffu && phase == 1) {{
        register f32* source asm("$15") = &D_0036dfd4;
        asm("" : "+r"(source));
{inner_barrier}        D_01d498c0 = *source;
    }}
    if (priority == 0xffffu && phase == 1) {{
        register f32* source asm("$15") = &D_0036dfd8;
        asm("" : "+r"(source));
{inner_barrier}        D_01d498c4 = *source;
    }}
    if (priority == 0xffffu && phase == 1) func_0031b9e0(&D_01d498d0);
{post}}}
"""

# ------------------------------------------------------------------ 00241f20
for pin in ("11", "12", "13", "14"):
    BODY[f"v_pin{pin}_241f20"] = f"""
void func_00241f20(u32 phase, u32 priority) {{
    if (priority == 0xffffu && phase == 1) {{
        register u32* base asm("${pin}") = D_01dae688;
        asm("" : "+r"(base));
        u32 first = D_0035ebf8;
        base[4] = 0;
        base[1] = 0x3c4;
        base[0] = first;
        u32 second = D_0035ebfc;
        base[2] = second;
        base[3] = 0x8a58;
        base[5] = 0x00010000u | 0xfc0u;
    }}
}}
"""

BODY["v_barrier_241f20"] = """
void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32* base asm("$12") = D_01dae688;
        asm("" : "+r"(base));
        u32 first = D_0035ebf8;
        base[4] = 0;
        asm volatile("" ::: "memory");
        base[1] = 0x3c4;
        asm volatile("" ::: "memory");
        base[0] = first;
        u32 second = D_0035ebfc;
        base[2] = second;
        base[3] = 0x8a58;
        base[5] = 0x00010000u | 0xfc0u;
    }
}
"""

# ------------------------------------------------------------------ 00104210
PIN15 = """    register s32 positive asm("$15") = 0 < value;
    asm("" : "+r"(positive));
    register s32 current asm("$14") = value;
    register s32 one asm("$12") = 1;
    asm("" : "+r"(one));
    if (!positive) current = one;
    register u32 selected asm("$4") = 2;
    asm("" : "+r"(selected));
    D_0032ba84 = current;
"""

SHAPES = {
    "a": """    if (current == 2) { func_00104200(selected); return; }
    if (current < 3) {
        if (current != 1) { func_00104200(selected); return; }
        selected = 1;
        return;
    }
    if (current != 3) return;
    selected = 3;
    func_00104200(selected);
""",
    "b": """    if (current == 2) { func_00104200(selected); return; }
    if (current >= 3) {
        if (current == 3) { selected = 3; func_00104200(selected); }
        return;
    }
    if (current != 1) { func_00104200(selected); return; }
    selected = 1;
""",
    "c": """    if (current == 2) goto tail;
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
""",
    "d": """    if (current == 2) { func_00104200(selected); return; }
    if (!(current < 3)) {
        if (current != 3) return;
        selected = 3;
        func_00104200(selected);
        return;
    }
    if (current == 1) { selected = 1; return; }
    func_00104200(selected);
""",
}

for tag, shape in SHAPES.items():
    BODY[f"w_{tag}_104210"] = ("void func_00104210(s32 value) {\n" + PIN15 + shape + "}\n")

# ------------------------------------------------------------------------
os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))