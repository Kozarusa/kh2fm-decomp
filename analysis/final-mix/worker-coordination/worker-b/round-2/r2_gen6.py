import os
BASE = "C:/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments"

HEAD = '''#include "../common/types.h"
DECLS
u32 func_00310620(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
BODY
}
'''

def build(decls, body):
    return HEAD.replace("DECLS", decls).replace("BODY", body)

TAIL = '''  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    CALL
  }
  return uVar2;
}'''

V = {
 # 1: first callee takes 5+ args (forces 1 stack arg area), second takes 2
 "v01": ('''extern "C" s32 func_0030edb0(s32,s32,s32,s32,s32);
extern "C" void func_0030ee00(s32,s32);
extern "C" s32 func_003105b0(s32);''',
        '''  lVar1 = func_0030edb0(param_1,param_1,param_1,param_1,param_1) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(param_1,param_1);
  }
  return uVar2;'''),
 # 2: both callees take 6 args (two stack arg words each)
 "v02": ('''extern "C" s32 func_0030edb0(s32,s32,s32,s32,s32,s32);
extern "C" void func_0030ee00(s32,s32,s32,s32,s32,s32);
extern "C" s32 func_003105b0(s32);''',
        '''  lVar1 = func_0030edb0(0,0,0,0,0,0) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(0,0,0,0,0,0);
  }
  return uVar2;'''),
 # 3: one 64-bit stack argument each (double param -> passed in the stack in o32)
 "v03": ('''extern "C" s32 func_0030edb0(double);
extern "C" void func_0030ee00(double);
extern "C" s32 func_003105b0(s32);''',
        '''  lVar1 = func_0030edb0(1.0) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(2.0);
  }
  return uVar2;'''),
 # 4: callee returns a 64-bit value
 "v04": ('''extern "C" long long func_0030edb0(s32);
extern "C" long long func_0030ee00(s32);
extern "C" s32 func_003105b0(s32);''',
        '''  lVar1 = func_0030edb0(0) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(0);
  }
  return uVar2;'''),
 # 5: our own function returns a 64-bit value
 "v05": ('''extern "C" s32 func_0030edb0(...);
extern "C" void func_0030ee00(...);
extern "C" s32 func_003105b0(...);''',
        '''  lVar1 = func_0030edb0() != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return (u32)uVar2;'''),
 # 6: one callee takes a 64-bit struct by value
 "v06": ('''struct pair { int lo; int hi; };
extern "C" s32 func_0030edb0(pair);
extern "C" void func_0030ee00(pair);
extern "C" s32 func_003105b0(s32);''',
        '''  lVar1 = func_0030edb0(pair{0,0}) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(pair{0,0});
  }
  return uVar2;'''),
}

for tag, (decls, body) in V.items():
    text = build(decls, body)
    if tag == "v05":
        text = text.replace("u32 func_00310620(u32 param_1)", "long long func_00310620(u32 param_1)")
    open(os.path.join(BASE, "fm_worker_b_round2_00310620_%s.cpp" % tag), "w").write(text)
print("generated", len(V))