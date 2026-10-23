#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00100350(...);
extern "C" u64 func_00101ce0(...);
extern "C" u64 func_00108698(...);
extern "C" u64 func_00138988(...);
extern "C" u64 func_00138de0(...);
extern "C" u64 func_0014b9a8(...);
extern "C" u64 func_001ddd10(...);
extern "C" u64 func_002ff3fc(...);
extern "C" u64 func_003032d0(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_0030ff08(...);
extern "C" u64 func_00310518(...);
extern "C" u64 func_00310670(...);
extern "C" u64 func_00311aa0(...);
extern "C" u64 func_00311af0(...);
extern "C" u64 func_00313c58(...);
extern "C" u64 func_00313f98(...);
extern "C" u64 func_003141e8(...);
extern "C" u64 func_00314698(...);
extern "C" u64 func_003146c8(...);
extern "C" u64 func_003147a0(...);
extern "C" u64 func_003149e8(...);
extern "C" u64 func_00314b90(...);

void func_00313e80(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u8 auStack_80 [32];
  u8 auStack_60 [32];
  u8 auStack_40 [32];
  u64 uStack_20;
  u64 uStack_18;
  
  uStack_20 = param_1;
  uStack_18 = param_2;
  func_003147a0(&uStack_20,auStack_80);
  func_003147a0(&uStack_18,auStack_60);
  uVar1 = func_00313c58(auStack_80,auStack_60,auStack_40);
  func_003146c8(uVar1);
  return;
}

void func_00313f40(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u8 auStack_80 [32];
  u8 auStack_60 [32];
  u8 auStack_40 [32];
  u64 uStack_20;
  u64 uStack_18;
  
  uStack_20 = param_1;
  uStack_18 = param_2;
  func_003147a0(&uStack_20,auStack_80);
  func_003147a0(&uStack_18,auStack_60);
  uVar1 = func_00313f98(auStack_80,auStack_60,auStack_40);
  func_003146c8(uVar1);
  return;
}

void func_00314190(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u8 auStack_60 [32];
  u8 auStack_40 [32];
  u64 uStack_20;
  u64 uStack_18;
  
  uStack_20 = param_1;
  uStack_18 = param_2;
  func_003147a0(&uStack_20,auStack_60);
  func_003147a0(&uStack_18,auStack_40);
  uVar1 = func_003141e8(auStack_60,auStack_40);
  func_003146c8(uVar1);
  return;
}
