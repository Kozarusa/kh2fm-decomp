#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001050d8(...);
extern "C" s64 func_0010cce0(...);
extern "C" u32 func_00127c70(...);
extern "C" u32 func_001325c8(...);
extern "C" u32 func_00132720(...);
extern "C" u64 func_00132c68(...);
extern "C" u32 func_00135e50(...);
extern "C" u32 func_00136020(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_0013fd10(...);
extern "C" u32 func_0013fd78(...);
extern "C" u32 func_00152508(...);
extern "C" u32 func_00152598(...);
extern "C" u32 func_00154408(...);
extern "C" u32 func_00154ee8(...);
extern "C" u32 func_001581f8(...);
extern "C" u32 func_00167e28(...);
extern "C" u32 func_00168b38(...);
extern "C" s64 func_0016b7a0(...);
extern "C" s64 func_0016b800(...);
extern "C" u32 func_0016bc20(...);
extern "C" u64 func_0016bda8(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0016cc18(...);
extern "C" u16 func_0016f610(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" bool func_0017e3b8(...);
extern "C" int func_0017ec98(...);
extern "C" s64 func_0017edf0(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_001802d8(...);
extern "C" u32 func_00180408(...);
extern "C" u32 func_00181178(...);
extern "C" bool func_00181500(...);
extern "C" u32 func_00185890(...);
extern "C" u32 func_00185da8(...);
extern "C" u32 func_00186078(...);
extern "C" bool func_00186ce8(...);
extern "C" u32 func_00188948(...);
extern "C" int func_00188fe0(...);
extern "C" u32 func_0018a818(...);
extern "C" u32 func_0018d940(...);
extern "C" u64 func_0018da18(...);
extern "C" u32 func_00190128(...);
extern "C" s64 func_00190208(...);
extern "C" s64 func_00190730(...);
extern "C" int func_00195468(...);
extern "C" u32 func_00195530(...);
extern "C" u32 func_00195558(...);
extern "C" bool func_0019ba60(...);
extern "C" u32 func_0019c090(...);
extern "C" u64 func_0019c410(...);
extern "C" u32 func_001a1a20(...);
extern "C" u16 func_001a67b0(...);
extern "C" u32 func_001ab800(...);
extern "C" u32 func_001ab810(...);
extern "C" u32 func_001abb28(...);
extern "C" u32 func_001b7df0(...);
extern "C" u32 func_001b8e88(...);
extern "C" u16 func_001bc010(...);
extern "C" u32 func_001bc730(...);
extern "C" u32 func_001bd2d0(...);
extern "C" u32 func_001bd5b0(...);
extern "C" u32 func_001bd618(...);
extern "C" u32 func_001bdc18(...);
extern "C" u64 func_001c0320(...);
extern "C" bool func_001c0cd8(...);
extern "C" u32 func_001c16f0(...);
extern "C" u32 func_001c6ee8(...);
extern "C" u32 func_001cdbc8(...);
extern "C" u32 func_001d17b0(...);
extern "C" u32 func_001db8b8(...);
extern "C" u32 func_001dc5f0(...);
extern "C" u32 func_00239700(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_003208a8(...);

int func_001182d0(void)

{
  s64 lVar1;
  s64 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 0;
  while (lVar2 = func_0010cce0(lVar2), lVar2 != 0) {
    lVar1 = func_0019c410(lVar2);
    if (lVar1 == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}

int func_0016c028(int param_1)

{
  s64 lVar1;
  int iVar2;
  
  lVar1 = func_001c0cd8();
  iVar2 = param_1 + 0x70;
  if (lVar1 == 0) {
    iVar2 = param_1 + 0x540;
  }
  return iVar2;
}

void func_00189028(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u64 uVar1;
  
  uVar1 = func_00188fe0();
  func_00188948(uVar1,param_3,param_4);
  return;
}
