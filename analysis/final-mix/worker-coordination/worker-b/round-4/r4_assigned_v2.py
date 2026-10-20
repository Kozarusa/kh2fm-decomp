"""Round-4 assigned targets: refined variants from the offline word diffs.

Refinements over the first pass (r4_assigned_diff.py):
  * 00242500 / 00109e30 -- the ONLY structural difference is which arm GCC makes
    the fall-through. Target makes the NON-ZERO arm the fall-through in both, the
    registered sources have the ZERO arm inline. Inverting the condition is the fix.
  * 001ac310 -- the stores must go through the param_1+3 pointer that is already
    passed to both callees (s1 = a0+12), giving sw t7,0x148(s1) / sw t6,0x14c(s1).
  * 001e7230 -- the masked remainder needs its own local so a1 survives both loops.
  * 001576e8 -- inline the inner call in the outer call's argument list (the
    0017ee68 mechanism): that makes GCC emit mov a1,v0 BEFORE the addiu a0.
  * 0014b950 -- same instruction multiset, different order; restructure the pack.
"""

import os

OUT = "analysis/final-mix/recovery-experiments"

VARIANTS = {}

# ---------------------------------------------------------------- 00109e30
# Target: andi a0,a0,0xff ; beq a0,zero (zero arm out-of-line at 76) ;
#         sd ra,8(sp) lands in the branch delay slot (no sra to compete with it).
# Two independent fixes: u8 parameter (supplies the andi, removes the sll/sra pair)
# and inverting the test (makes the non-zero call the fall-through).
VARIANTS["00109e30"] = {
"v03": r'''
#include "../common/types.h"

extern "C" u64 func_00133f80(...);
extern "C" u64 func_00133f60(...);
extern "C" void func_00133ea8(...);
extern "C" void func_00109330(...);
extern "C" void func_00109340(...);

u64 func_00109e30(u8 param_1)
{
  u64 uVar1;
  if (param_1 != 0) {
    uVar1 = func_00133f80();
  }
  else {
    uVar1 = func_00133f60();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
''',
# control: right polarity, wrong param type
"v04": r'''
#include "../common/types.h"

extern "C" u64 func_00133f80(...);
extern "C" u64 func_00133f60(...);
extern "C" void func_00133ea8(...);
extern "C" void func_00109330(...);
extern "C" void func_00109340(...);

u64 func_00109e30(char param_1)
{
  u64 uVar1;
  if (param_1 != 0) {
    uVar1 = func_00133f80();
  }
  else {
    uVar1 = func_00133f60();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
''',
# control: right param type, wrong polarity
"v05": r'''
#include "../common/types.h"

extern "C" u64 func_00133f80(...);
extern "C" u64 func_00133f60(...);
extern "C" void func_00133ea8(...);
extern "C" void func_00109330(...);
extern "C" void func_00109340(...);

u64 func_00109e30(u8 param_1)
{
  u64 uVar1;
  if (param_1 == 0) {
    uVar1 = func_00133f60();
  }
  else {
    uVar1 = func_00133f80();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
''',
}

# ---------------------------------------------------------------- 00242500
# Target: beq v0,zero -> out-of-line zero arm at 72 which builds 999999 with
#         lui/ori and branches BACK into the shared store/return tail at 44.
#         The non-zero arm (jal 001058e8; lw t7,0x2440(v0); addu t7,t7,s0) is the
#         fall-through. The registered source is identical apart from polarity,
#         and its shared tail already matches word for word.
VARIANTS["00242500"] = {
"v02": r'''
#include "../common/types.h"

extern "C" u32 func_002424c0(...);
extern "C" u32 func_001058e8(...);

u32 func_00242500(s32 param_1)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002424c0();
  if (lVar2 != 0) {
    param_1 = *(int *)(func_001058e8() + 0x2440) + param_1;
  }
  else {
    param_1 = 999999;
  }
  uVar1 = func_001058e8();
  *(int *)(uVar1 + 0x2440) = param_1;
  return *(int *)(uVar1 + 0x2440);
}
''',
# same polarity but the first call bound to a local (does it change the arm layout?)
"v03": r'''
#include "../common/types.h"

extern "C" u32 func_002424c0(...);
extern "C" u32 func_001058e8(...);

u32 func_00242500(s32 param_1)
{
  s32 lVar2;
  u32 uVar1;
  lVar2 = func_002424c0();
  if (lVar2 != 0) {
    uVar1 = func_001058e8();
    param_1 = *(int *)(uVar1 + 0x2440) + param_1;
  }
  else {
    param_1 = 999999;
  }
  uVar1 = func_001058e8();
  *(int *)(uVar1 + 0x2440) = param_1;
  return *(int *)(uVar1 + 0x2440);
}
''',
}

# ---------------------------------------------------------------- 001ac310
# Target: addiu s1,a0,12 then lw t6,8(s0) / lw t7,4(s0) (param_1[2] BEFORE
#         param_1[1]) and sw t7,0x148(s1) / sw t6,0x14c(s1).
#         0x148 = 12 + 0x4f*4 and 0x14c = 12 + 0x50*4, so the stores go through
#         the SAME param_1+3 pointer that both callees receive.
VARIANTS["001ac310"] = {
"v04": r'''
#include "../common/types.h"

extern "C" void func_0023acd8(...);
extern "C" void func_0023ade0(...);

void func_001ac310(s32 *param_1)
{
  s32 *puVar1;
  if (*param_1 != 0) {
    puVar1 = param_1 + 3;
    func_0023acd8(puVar1);
    puVar1[0x4f] = param_1[1];
    puVar1[0x50] = param_1[2];
    func_0023ade0(puVar1);
    return;
  }
  return;
}
''',
# same, but the two loaded values bound to locals first (target loads [2] then [1])
"v05": r'''
#include "../common/types.h"

extern "C" void func_0023acd8(...);
extern "C" void func_0023ade0(...);

void func_001ac310(s32 *param_1)
{
  s32 *puVar1;
  s32 iVar1;
  s32 iVar2;
  if (*param_1 != 0) {
    puVar1 = param_1 + 3;
    func_0023acd8(puVar1);
    iVar2 = param_1[2];
    iVar1 = param_1[1];
    puVar1[0x4f] = iVar1;
    puVar1[0x50] = iVar2;
    func_0023ade0(puVar1);
    return;
  }
  return;
}
''',
# no hoisted pointer: address arithmetic written inline
"v06": r'''
#include "../common/types.h"

extern "C" void func_0023acd8(...);
extern "C" void func_0023ade0(...);

void func_001ac310(s32 *param_1)
{
  if (*param_1 != 0) {
    func_0023acd8(param_1 + 3);
    param_1[0x55] = param_1[1];
    param_1[0x56] = param_1[2];
    func_0023ade0(param_1 + 3);
    return;
  }
  return;
}
''',
}

# ---------------------------------------------------------------- 001e7230
# Target: andi t6,a1,0x3 at both loop entries and t6 is the SECOND loop's counter,
#         so a1 (the incoming parameter) is never destroyed. The registered source
#         assigns back into param_2, which costs the extra andi at 48.
VARIANTS["001e7230"] = {
"v02": r'''
#include "../common/types.h"

void func_001e7230(u32 *param_1,u32 param_2)
{
  s32 iVar1;
  u32 uVar1;
  iVar1 = ((s32)param_2) >> 2;
  while (iVar1 = iVar1 + -1,iVar1 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  uVar1 = param_2 & 3;
  while (uVar1 = uVar1 - 1,uVar1 != 0xffffffff) {
    *(u8 *)param_1 = 0;
    param_1 = (u32 *)((int)param_1 + 1);
  }
  return;
}
''',
# control: separate local but written after the first loop (same as v02 by another path)
"v03": r'''
#include "../common/types.h"

void func_001e7230(u32 *param_1,u32 param_2)
{
  s32 iVar1;
  u32 uVar1;
  uVar1 = param_2 & 3;
  iVar1 = ((s32)param_2) >> 2;
  while (iVar1 = iVar1 + -1,iVar1 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  while (uVar1 = uVar1 - 1,uVar1 != 0xffffffff) {
    *(u8 *)param_1 = 0;
    param_1 = (u32 *)((int)param_1 + 1);
  }
  return;
}
''',
}

# ---------------------------------------------------------------- 001576e8
# Target: jal 00155d58 ; mov a1,v0 ; jal 00138c10 ; addiu a0,s0,0x1a30
#         i.e. the previous call's result is moved into a1 BEFORE the address
#         argument is materialised. The registered source pre-binds the result to
#         uVar1 and pre-computes (int)param_1. Inlining the inner call in the outer
#         call's argument list is what flipped this exact pair in round 2's 0017ee68.
VARIANTS["001576e8"] = {
"v03": r'''
#include "../common/types.h"

extern "C" u64 func_00155d58(...);
extern "C" void func_00138c10(...);
extern "C" void func_00154408(...);

void func_001576e8(u32 *param_1)
{
  func_00138c10(func_00155d58(param_1,0),(int)param_1 + 0x1a30);
  func_00138c10(func_00155d58(param_1,1),(int)param_1 + 0x1bcc);
  func_00138c10(func_00155d58(param_1,2),(int)param_1 + 0x20a0);
  func_00154408((char *)param_1 + 0x40,*(u32 *)(param_1 + 6));
}
''',
# same nesting but the outer argument order written result-first
"v04": r'''
#include "../common/types.h"

extern "C" u64 func_00155d58(...);
extern "C" void func_00138c10(...);
extern "C" void func_00154408(...);

void func_001576e8(u32 *param_1)
{
  func_00138c10((int)param_1 + 0x1a30,func_00155d58(param_1,0));
  func_00138c10((int)param_1 + 0x1bcc,func_00155d58(param_1,1));
  func_00138c10((int)param_1 + 0x20a0,func_00155d58(param_1,2));
  func_00154408((char *)param_1 + 0x40,*(u32 *)(param_1 + 6));
}
''',
# nested, but the base pointer bound to an int local first (as the registered source does)
"v05": r'''
#include "../common/types.h"

extern "C" u64 func_00155d58(...);
extern "C" void func_00138c10(...);
extern "C" void func_00154408(...);

void func_001576e8(u32 *param_1)
{
  s32 iVar1;
  iVar1 = (int)param_1;
  func_00138c10(func_00155d58(param_1,0),iVar1 + 0x1a30);
  func_00138c10(func_00155d58(param_1,1),iVar1 + 0x1bcc);
  func_00138c10(func_00155d58(param_1,2),iVar1 + 0x20a0);
  func_00154408((char *)param_1 + 0x40,*(u32 *)(param_1 + 6));
}
''',
}

# ---------------------------------------------------------------- 0014b950
# Target and compiled contain the SAME instruction multiset; only the order of the
# independent "and 0xffff, add -1" pairs, their shifts, and the two or operands
# differ. Try named locals for the two packed halves.
VARIANTS["0014b950"] = {
"v03": r'''
#include "../common/types.h"

void func_0014b950(s32 *param_1,s16 param_2,s16 param_3,u16 param_4,u16 param_5)
{
  s64 lVar1;
  s64 lVar2;
  lVar2 = (s64)(param_3 + (param_5 & 0xffff) - 1);
  lVar1 = (s64)(param_2 + (param_4 & 0xffff) - 1);
  *(s64 *)(param_1 + 4) = (s64)param_2 | lVar1 << 0x10 | (s64)param_3 << 0x20 | lVar2 << 0x30;
}
''',
# statement form: build the s64 field by field
"v04": r'''
#include "../common/types.h"

void func_0014b950(s32 *param_1,s16 param_2,s16 param_3,u16 param_4,u16 param_5)
{
  s64 *psVar1;
  s64 lVar1;
  psVar1 = (s64 *)(param_1 + 4);
  lVar1 = (s64)param_2;
  lVar1 |= (s64)(param_2 + (param_4 & 0xffff) - 1) << 0x10;
  lVar1 |= (s64)param_3 << 0x20;
  lVar1 |= (s64)(param_3 + (param_5 & 0xffff) - 1) << 0x30;
  *psVar1 = lVar1;
}
''',
# halves as locals, or-ed separately
"v05": r'''
#include "../common/types.h"

void func_0014b950(s32 *param_1,s16 param_2,s16 param_3,u16 param_4,u16 param_5)
{
  s64 lVar1;
  s64 lVar2;
  lVar1 = (s64)param_2 | (s64)(param_2 + (param_4 & 0xffff) - 1) << 0x10;
  lVar2 = (s64)param_3 | (s64)(param_3 + (param_5 & 0xffff) - 1) << 0x10;
  *(s64 *)(param_1 + 4) = lVar1 | lVar2 << 0x20;
}
''',
}

if __name__ == "__main__":
    os.makedirs(OUT, exist_ok=True)
    names = []
    for addr, vs in VARIANTS.items():
        for tag, body in sorted(vs.items()):
            fn = f"fm_worker_b_round4_{addr}_{tag}.cpp"
            with open(os.path.join(OUT, fn), "w", newline="\n") as f:
                f.write(body.lstrip())
            names.append(f"/mnt/c/Users/KoZa/Documents/AGENTS/Codex/{OUT}/{fn}")
    listfile = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-4/r4_list_v2.txt"
    with open(listfile, "w", newline="\n") as f:
        f.write("\n".join(names) + "\n")
    print(f"{len(names)} variants -> {listfile}")
    for n in names:
        print("  ", os.path.basename(n))