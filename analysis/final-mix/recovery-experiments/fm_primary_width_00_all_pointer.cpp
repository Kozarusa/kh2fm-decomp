#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001050d8(...);
extern "C" s32 func_0010cce0(...);
extern "C" u32 func_00127c70(...);
extern "C" u32 func_001325c8(...);
extern "C" u32 func_00132720(...);
extern "C" u32 func_00132c68(...);
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
extern "C" s32 func_0016b7a0(...);
extern "C" s32 func_0016b800(...);
extern "C" u32 func_0016bc20(...);
extern "C" u32 func_0016bda8(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0016cc18(...);
extern "C" u16 func_0016f610(...);
extern "C" u32 func_0017c030(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" bool func_0017e3b8(...);
extern "C" int func_0017ec98(...);
extern "C" s32 func_0017edf0(...);
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
extern "C" u32 func_0018da18(...);
extern "C" u32 func_00190128(...);
extern "C" s32 func_00190208(...);
extern "C" s32 func_00190730(...);
extern "C" int func_00195468(...);
extern "C" u32 func_00195530(...);
extern "C" u32 func_00195558(...);
extern "C" bool func_0019ba60(...);
extern "C" u32 func_0019c090(...);
extern "C" u32 func_0019c410(...);
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
extern "C" u32 func_001c0320(...);
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

void func_00132e28(u8* param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  s32 lVar3;
  
  lVar3 = func_00132c68();
  iVar2 = (int)lVar3;
  if (lVar3 != 0) {
    lVar3 = func_001325c8(param_1,0xffff,param_2);
    if (-1 < lVar3) {
      iVar1 = *(int *)((int)lVar3 * 4 + iVar2 + *(int *)(iVar2 + 0x1c));
      *(u32 *)((int)param_1 + 0x14) = *(u32 *)((int)param_1 + 0x14) | 4;
      func_00132720(param_1,iVar2 + iVar1);
      return;
    }
  }
  return;
}

void func_001954a0(u8* param_1,u16 param_2)

{
  s32 lVar1;
  
  lVar1 = func_00195530();
  if (lVar1 == 0) {
    lVar1 = func_00195468(param_1,0);
    if (-1 < lVar1) {
      *(u16 *)((int)lVar1 * 2 + (int)param_1 + 8) = param_2;
    }
  }
  return;
}

void func_001b6dd0(u8* param_1,u32 *param_2)

{
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  func_0017c4c8(param_1,&uStack_20);
  *(u8 *)((int)param_1 + 0x514) = 3;
  return;
}

void func_001c1890(u8* param_1)

{
  func_003208a8(*(int *)((int)param_1 + 0x1c) + 0xc,param_1);
  func_001db8b8(*(int *)((int)param_1 + 0x1c) + 0x14,param_1);
  return;
}
