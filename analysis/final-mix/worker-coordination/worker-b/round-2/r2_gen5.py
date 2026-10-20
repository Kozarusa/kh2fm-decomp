import os
BASE = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments"
HEAD = '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

s32 func_0019c0f8(s32 param_1)
{
  s32 lVar1;
  s32 lVar2;
  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = EXPR;
    }
  }
  return lVar1;
}
'''

V = {
 "v16": "((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200u) == 0u)",
 "v17": "(uVar2 & 0x200) == 0",
 "v18": "(!(*(int *)(*(int *)(param_1 + 0xc) + 8) & 0x200))",
 "v19": "((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0 ? 1 : 0)",
 "v20": "((*(u32 *)(*(int *)(param_1 + 0xc) + 8) >> 9) & 1) == 0",
 "v21": "((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == uVar3)",
 "v22": "((*(u16 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0)",
 "v23": "((*(unsigned int *)(*(int *)(param_1 + 0xc) + 8) & 512) == 0)",
}
DECLS = {
 "v17": "  u32 uVar2;\n",
 "v21": "  u32 uVar2;\n  u32 uVar3;\n",
}
INIT = {
 "v17": "  uVar2 = *(u32 *)(*(int *)(param_1 + 0xc) + 8);\n",
 "v21": "  uVar2 = *(u32 *)(*(int *)(param_1 + 0xc) + 8);\n  uVar3 = 0;\n",
}
for tag, expr in V.items():
    body = HEAD.replace("EXPR", expr)
    body = body.replace("  s32 lVar2;\n", "  s32 lVar2;\n" + DECLS.get(tag, ""))
    body = body.replace("  lVar1 = 0;\n", INIT.get(tag, "") + "  lVar1 = 0;\n")
    open(os.path.join(BASE, "fm_worker_b_round2_0019c0f8_%s.cpp" % tag), "w").write(body)

HEAD3 = '''#include "../common/types.h"
extern "C" void func_002f3490(...);

'''
V3 = {
 # conditional-expression form with pre-assigned constant
 "v23": HEAD3 + '''u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 1;
  uVar1 = param_2 == uVar1 ? *param_1 >> 8 & 1 : 0;
  if (uVar1 != 0 || param_2 != 1) {
  }
  return uVar1;
}
''',
 # if/else where the else is the fall-through body (source-order swap with goto)
 "v24": HEAD3 + '''u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 1;
  if (param_2 == uVar1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
''',
 # nested if instead of else (else body guarded)
 "v25": HEAD3 + '''u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
  }
  return uVar1;
}
''',
 # constant held in a variable declared before the pointer parameter use
 "v26": HEAD3 + '''u32 func_002f3bb8(u32 *param_1,s32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  uVar2 = 1;
  if (param_2 == uVar2) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
  } else {
    func_002f3490();
    uVar1 = 0;
  }
  return uVar1;
}
''',
}
for tag, body in V3.items():
    open(os.path.join(BASE, "fm_worker_b_round2_002f3bb8_%s.cpp" % tag), "w").write(body)
print("generated", len(V) + len(V3))