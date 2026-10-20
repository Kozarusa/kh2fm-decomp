import os
BASE = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments"

HEAD19 = '''#include "../common/types.h"
extern "C" s32 func_0019c090(...);

'''
PRE = '''  lVar1 = 0;
  lVar2 = func_0019c090();
  if (lVar2 != 0) {
    if ((*(u32 *)(param_1 + 0x160) & 0x20) == 0) {
      lVar1 = EXPR;
    }
  }
  return lVar1;
}
'''

V19 = {
 # v10: logical NOT form -> single sltiu
 "v10": HEAD19 + "s32 func_0019c0f8(s32 param_1)\n{\n  s32 lVar1;\n  s32 lVar2;\n" +
        PRE.replace("EXPR", "!(*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200)"),
 # v11: ternary form
 "v11": HEAD19 + "s32 func_0019c0f8(s32 param_1)\n{\n  s32 lVar1;\n  s32 lVar2;\n" +
        PRE.replace("EXPR", "((*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) != 0) ? 0 : 1"),
 # v12: u32 result variable
 "v12": HEAD19 + "u32 func_0019c0f8(s32 param_1)\n{\n  u32 lVar1;\n  s32 lVar2;\n" +
        PRE.replace("EXPR", "(*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200) == 0"),
 # v13: collapsed single condition, result pre-zeroed
 "v13": HEAD19 + "s32 func_0019c0f8(s32 param_1)\n{\n  s32 lVar1;\n  s32 lVar2;\n" + '''  lVar1 = 0;
  lVar2 = func_0019c090();
  if ((lVar2 != 0) && ((*(u32 *)(param_1 + 0x160) & 0x20) == 0)) {
    lVar1 = !(*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200);
  }
  return lVar1;
}
''',
 # v14: bool result, NOT form
 "v14": HEAD19 + "bool func_0019c0f8(s32 param_1)\n{\n  bool lVar1;\n  s32 lVar2;\n" +
        PRE.replace("EXPR", "!(*(u32 *)(*(int *)(param_1 + 0xc) + 8) & 0x200)"),
 # v15: sub-expression through a local pointer load
 "v15": HEAD19 + "s32 func_0019c0f8(s32 param_1)\n{\n  s32 lVar1;\n  s32 lVar2;\n" +
        PRE.replace("EXPR", "(*(u32 *)(*(u32 *)(param_1 + 0xc) + 8) & 0x200) == 0"),
}

HEAD3 = '''#include "../common/types.h"
extern "C" void func_002f3490(...);

'''
THEN = '''  if (param_2 == 1) {
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
'''
V3 = {
 # v17: reversed comparison spelling
 "v17": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n" +
        THEN.replace("param_2 == 1", "1 == param_2"),
 # v18: pre-zeroed result, no assignment in else
 "v18": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n" +
        '''  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
    return uVar1;
  }
  func_002f3490();
  return uVar1;
}
''',
 # v19: pre-zeroed + shared epilogue label
 "v19": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n" +
        '''  uVar1 = 0;
  if (param_2 == 1) {
    uVar1 = *param_1;
    uVar1 = uVar1 >> 8;
    uVar1 = uVar1 & 1;
    goto end;
  }
  func_002f3490();
end:
  return uVar1;
}
''',
 # v20: value kept in a separate local
 "v20": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n  u32 uVar2;\n" +
        '''  uVar1 = 1;
  if (param_2 == uVar1) {
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
 # v21: bit test without a separate shift variable
 "v21": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n" +
        '''  uVar1 = 1;
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
 # v22: same but the constant compared through a separate local
 "v22": HEAD3 + "u32 func_002f3bb8(u32 *param_1,s32 param_2)\n{\n  u32 uVar1;\n  u32 uVar2;\n" +
        '''  uVar2 = 1;
  if (param_2 == uVar2) {
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

groups = {"0019c0f8": V19, "002f3bb8": V3}
for addr, vs in groups.items():
    names = []
    for tag, body in vs.items():
        fn = "fm_worker_b_round2_%s_%s" % (addr, tag)
        open(os.path.join(BASE, fn + ".cpp"), "w").write(body)
        names.append("/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/%s.cpp" % fn)
    open("C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-2/r2_list_%s_c.txt" % addr,
         "w").write("\n".join(names) + "\n")
print("generated", sum(len(v) for v in groups.values()))