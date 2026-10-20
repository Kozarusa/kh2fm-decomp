import os
BASE = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments"

V19 = {
 # A: result register live across the call -> callee-saved s1 (mirrors target)
 "v06": '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  s32 lVar2;
  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
    }
  }
  return lVar1;
}
''',
 # B: same but bool
 "v07": '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

bool func_0019c0f8(s32 param_1)
{
  bool bVar1;
  s32 lVar2;
  bVar1 = false;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      bVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
    }
  }
  return bVar1;
}
''',
 # C: single combined condition with the zero default
 "v08": '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

bool func_0019c0f8(s32 param_1)
{
  s32 lVar2;
  lVar2 = func_0019c090();
  if ((lVar2 != 0) && ((*(u32 *)(param_1 + 0x160) & 0x20) == 0)) {
    return (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  return false;
}
''',
 # D: else-if chain with explicit 1 (Ghidra shape) but result pre-zeroed
 "v09": '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  s32 lVar2;
  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 == 0) {
    lVar1 = 0;
  }
  else if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
    lVar1 = (*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0;
  }
  else {
    lVar1 = 1;
  }
  return lVar1;
}
''',
}

VF3 = {
 # E: negated condition
 "v09": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 != 1) {
    func_002f3490();
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  }
  return uVar1;
}
''',
 # F: return inside each branch
 "v10": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  if (param_2 == 1) {
    return *param_1 >> 8 & 1;
  }
  func_002f3490();
  return 0;
}
''',
 # G: switch with case 1 / default
 "v11": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  switch (param_2) {
    case 1:
      uVar1 = *param_1;
      uVar1 = uVar1 >> 8;
      uVar1 = uVar1 & 1;
      break;
    default:
      func_002f3490();
      uVar1 = 0;
      break;
  }
  return uVar1;
}
''',
 # H: result initialised to 1 before the test (forces $2 reuse)
 "v12": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 1;
  if (param_2 == uVar1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  }
  else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
''',
 # I: conditional-expression form
 "v13": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  if (param_2 == 1) {
    return (*param_1 >> 8) & 1;
  }
  func_002f3490();
  return 0u;
}
''',
 # J: goto style / explicit else last
 "v14": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
    return uVar1;
  }
  func_002f3490();
  uVar1 = 0;
  return uVar1;
}
''',
 # K: local alias for the shifted value
 "v15": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  if (param_2 == 1) {
    uVar2 = *param_1;
    uVar2 = uVar2 >> 8;
    uVar1 = uVar2 & 1;
  }
  else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
''',
 # L: unsigned param and 1u constant
 "v16": '''#include "../common/types.h"
extern "C" void func_002f3490(...);

u32 func_002f3bb8(u32 *param_1,u32 param_2)
{
  u32 uVar1;
  if (param_2 == 1u) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  }
  else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
''',
}

groups = {"0019c0f8": V19, "002f3bb8": VF3}
lists = []
for addr, vs in groups.items():
    names = []
    for tag, body in vs.items():
        fn = "fm_worker_b_round2_%s_%s" % (addr, tag)
        p = os.path.join(BASE, fn + ".cpp")
        open(p, "w").write(body)
        names.append("/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/%s.cpp" % fn)
    lf = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-2/r2_list_%s_b.txt" % addr
    open(lf, "w").write("\n".join(names) + "\n")
    lists.append(lf)
print("\n".join(lists))