#!/usr/bin/env python3
"""Worker B: final grid for 00241f20.

Two residual defects in the pinned variant:
  * the target keeps BOTH a page register ($t4 = 0x1db) and a full pointer
    ($t5 = $t4 - 6520) and stores the first global through the page
    (`sw $t2,-6520($t4)`) while the rest go through the full pointer;
  * the target's two loaded globals live in $t2/$t3, i.e. they are the first
    pseudos allocated, which only happens when the store sequence cannot be
    reordered by a barrier chain.
"""
import itertools
import os
import sys

WORK = sys.argv[1] if len(sys.argv) > 1 else "."

PRE = """typedef unsigned int u32;
extern u32 D_01dae688[6], D_0035ebf8, D_0035ebfc;
"""

BAR = '        asm volatile("" ::: "memory");\n'

def build(stmts, barriers, head):
    out = []
    for i, stmt in enumerate(stmts):
        if i in barriers:
            out.append(BAR.rstrip("\n"))
        out.append(stmt)
    if len(stmts) in barriers:
        out.append(BAR.rstrip("\n"))
    return head + "\n".join(out) + "\n    }\n}\n"

BODY = {}

PLAIN = ["        u32* base = D_01dae688;",
         "        u32 first = D_0035ebf8;",
         "        base[4] = 0;",
         "        base[1] = 0x3c4;",
         "        base[0] = first;",
         "        u32 second = D_0035ebfc;",
         "        base[2] = second;",
         "        base[3] = 0x8a58;",
         "        base[5] = 0x00010000u | 0xfc0u;"]
HEAD = ("void func_00241f20(u32 phase, u32 priority) {\n"
        "    if (priority == 0xffffu && phase == 1) {\n")

for r in (2, 3, 4):
    for sub in itertools.combinations(range(len(PLAIN)), r):
        tag = "".join(str(i) for i in sub)
        BODY[f"a_bar{tag}_241f20"] = build(PLAIN, set(sub), HEAD)

SPLIT = """void func_00241f20(u32 phase, u32 priority) {
    if (priority == 0xffffu && phase == 1) {
        register u32* page asm("$12") = D_01dae688;
        register u32* full asm("$13") = D_01dae688;
        asm("" : "+r"(page), "+r"(full));
        u32 first = D_0035ebf8;
        full[4] = 0;
        full[1] = 0x3c4;
        page[0] = first;
        u32 second = D_0035ebfc;
        full[2] = second;
        full[3] = 0x8a58;
        full[5] = 0x00010000u | 0xfc0u;
    }
}
"""
BODY["b_split_241f20"] = SPLIT

SPLIT_BAR = SPLIT.replace("        full[4] = 0;", "        full[4] = 0;\n" + BAR.rstrip("\n")) \
                .replace("        full[1] = 0x3c4;", "        full[1] = 0x3c4;\n" + BAR.rstrip("\n")) \
                .replace("        page[0] = first;", "        page[0] = first;\n" + BAR.rstrip("\n")) \
                .replace("        full[2] = second;", "        full[2] = second;\n" + BAR.rstrip("\n"))
BODY["b_splitbar_241f20"] = SPLIT_BAR

os.makedirs(WORK, exist_ok=True)
for name, body in sorted(BODY.items()):
    with open(os.path.join(WORK, name + ".cpp"), "w", newline="\n") as fh:
        fh.write(PRE + body)
print("\n".join(sorted(BODY)))