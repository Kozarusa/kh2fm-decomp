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

void func_001387f8(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  func_00239988((int)param_1 + 0x18);
  func_00138c10(param_1,param_4);
  *(u32 *)((int)param_1 + 0x188) = 0xffffffff;
  return;
}

void func_0016f6a0(int param_1)

{
  s32 lVar1;
  
  lVar1 = func_0016f610();
  if (lVar1 != 0) {
    func_00185890(*(u16 *)(param_1 + 0x4e),lVar1);
    return;
  }
  return;
}

void func_00172bd8(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  uVar2 = func_0016b7a0(param_1[1]);
  *(u32 *)(iVar1 + 4) = uVar2;
  return;
}

void func_00172c08(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  uVar2 = func_0016b800(param_1[1]);
  *(u32 *)(iVar1 + 4) = uVar2;
  return;
}

u32 func_0017f4e0(u32 param_1)

{
  int iVar1;
  u32 uVar2;
  s32 lVar3;
  
  uVar2 = func_0017ec98();
  lVar3 = func_0017edf0(param_1,uVar2);
  if ((lVar3 != 0) &&
     (iVar1 = func_00168b38(lVar3,9,0), *(int *)((int)param_1 + 0xc) != *(int *)(iVar1 + 8))) {
    return 1;
  }
  return 0;
}

bool func_001805a8(u32 param_1)

{
  u32 uVar1;
  s32 lVar2;
  
  uVar1 = func_0017ec98();
  uVar1 = func_0017edf0(param_1,uVar1);
  lVar2 = func_00180408(param_1,uVar1);
  return lVar2 != 0;
}

u32 func_00181570(u32 param_1,u32 param_2)

{
  u32 uVar1;
  s32 lVar2;
  
  lVar2 = func_00181500();
  if ((lVar2 == 0) && (lVar2 = func_00181500(param_2), lVar2 != 0)) {
    func_00181178(param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

void func_00185e78(u32 param_1)

{
  int iVar1;
  s32 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_00185da8(lVar2), lVar2 != 0) {
    iVar1 = *(int *)((int)lVar2 + 0x828);
    if (iVar1 != 0) {
      func_001b7df0(iVar1,param_1);
    }
  }
  return;
}

void func_0018f3a8(int *param_1)

{
  s32 lVar1;
  s32 lVar2;
  int iVar3;
  
  lVar2 = 0;
  iVar3 = 0;
  while (lVar2 = func_00185da8(lVar2), lVar2 != 0) {
    lVar1 = func_00186ce8(lVar2);
    if (lVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  }
  *param_1 = iVar3;
  return;
}

void func_001abd30(u32 *param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = 0;
  func_00239700(param_1 + 1);
  func_001abb28(param_1 + 0x57);
  uVar1 = func_001ab810();
  uVar2 = func_001ab800();
  func_00239988(param_1 + 1,uVar1,uVar2);
  return;
}

void func_001abd90(u32 *param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = 0;
  func_00239700(param_1 + 1);
  func_001abb28(param_1 + 0x57);
  uVar1 = func_001ab810();
  uVar2 = func_001ab800();
  func_00239988(param_1 + 1,uVar1,uVar2);
  return;
}

void func_001bd668(u32 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x8c0);
  while (iVar1 != 0) {
    func_001bd618(param_1,0);
    iVar1 = *(int *)((int)param_1 + 0x8c0);
  }
  return;
}

void func_001bdf38(u32 param_1)

{
  func_001bd2d0();
  func_001bd5b0(param_1,*(u32 *)((int)param_1 + 0xaa4),0);
  return;
}

void func_001befa8(u32 param_1)

{
  func_001bdc18();
  func_001bd5b0(param_1,*(u32 *)((int)param_1 + 0xaa4),0);
  return;
}
