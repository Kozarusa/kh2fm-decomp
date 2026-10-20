#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern u32* D_0035dcfc;
extern s32 D_0035ec94;
extern s32 D_0035ecc0;
extern s32 D_0035ecc4;
extern s32 D_0035eee0;
extern s32 D_0035ef50;
extern s32 D_0035ef54;
extern u16 D_0035ef70;
extern u16 D_0035f090;
extern u16 D_0035f092;
extern u16 D_0035f094;
extern u16 D_0035f096;
extern u16 D_0035f0a8;
extern u16 D_0035f0aa;
extern u16 D_0035f0ac;
extern s32 D_0035f0e4;
extern s32 D_0035f118;
extern s32 D_0035f11c;
extern u8 D_0035f120;
extern s32 D_0035f230;
extern s32 D_0035f2f8;
extern s32 D_0035f2fc;
extern s32 D_0035f304;
extern s32 D_0035f308;
extern s32 D_0035f30c;
extern s32 D_0035f310;
extern u32* D_0035f324;
extern s32 D_0035f404;
extern s32 D_0035f40c;
extern s32 D_0035f4d0;
extern s32 D_0035f4d4;
extern s32 D_0035f5e4;
extern s32 D_0035f620;
extern s32 D_0035f634;
extern s32 D_003616e8;
extern s32 D_00361f60;
extern f32 D_00362d80;
extern f32 D_00362d84;
extern f32 D_00362d88;
extern f32 D_00362d8c;
extern s32 D_003718d0;
extern s16 D_003726d0;
extern s16 D_003741f0;
extern s8 D_003743c0;
extern f32 D_00374438;
extern f32 D_00374fe0;
extern f32 D_00375870;
extern f32 D_00375874;
extern f32 D_00375884;
extern f32 D_00375888;
extern f32 D_0037588c;
extern f32 D_003758ec;
extern f32 D_0037599c;
extern f32 D_003759a0;
extern f32 D_003759a4;
extern f32 D_00375ae0;
extern f32 D_00375ae4;
extern f32 D_00375ae8;
extern f32 D_00375c8c;
extern f32 D_00375e24;
extern f32 D_00375e28;
extern f32 D_00375e2c;
extern f32 D_00375ef8;
extern s32 D_01e2a3c0;
extern s32 D_01e2a5e8;
extern s32 D_01e2a5ec;
extern s32 D_01e2a5f0;
extern s32 D_01e2a5f4;
extern s32 D_01e2a9f8;
extern s32 D_01e2aa78;
extern s32 D_01e2aa80;
extern s32 D_01e2aa84;
extern f32 D_01e2be10;
extern f32 D_01e2be14;
extern s32 D_01e2be18;
extern u8* D_01e2be1c;

void func_0028d188(int param_1)

{
  f32 uVar1;
  
  *(u32 *)(param_1 + 0x1b8) = 0;
  *(u8 *)(param_1 + 0x19c) = 0;
  uVar1 = D_00374438;
  *(u8 *)(param_1 + 0x19d) = 0;
*(f32*)(param_1 + 0x1a0) = uVar1;
  *(u32 *)(param_1 + 0x1a4) = 0;
  *(u32 *)(param_1 + 0x1a8) = 0;
  *(u32 *)(param_1 + 0x1ac) = 0;
  *(u32 *)(param_1 + 0x1b0) = 0;
  *(u32 *)(param_1 + 0x1b4) = 0;
  return;
}

void func_002be2d8(int param_1,int param_2,u32 *param_3)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar2 = param_3[2];
  iVar1 = *(int *)(param_2 * 4 + param_1 + 0x2c);
  uVar3 = param_3[1];
  *(u32 *)(iVar1 + 0x220) = *param_3;
  *(u32 *)(iVar1 + 0x224) = uVar3;
  *(u32 *)(iVar1 + 0x228) = uVar2;
*(f32*)(iVar1 + 0x22c) = D_00374fe0;
  return;
}

void func_002cb5d8(u32 param_1,u8 *param_2)

{
  f32 uVar1;
  
  *(u32 *)(param_2 + 0x14) = param_1;
  *param_2 = 0;
  uVar1 = D_00375884;
  *(u32 *)(param_2 + 0x8c) = 0xffffffff;
*(f32*)(param_2 + 0x1c) = uVar1;
  *(u32 *)(param_2 + 4) = 0;
  uVar1 = D_00375888;
  *(u32 *)(param_2 + 8) = 0;
*(f32*)(param_2 + 0x20) = uVar1;
  *(u32 *)(param_2 + 0xc) = 0;
  uVar1 = D_0037588c;
  param_2[0x10] = 0;
*(f32*)(param_2 + 0x24) = uVar1;
  param_2[0x84] = 1;
  *(u32 *)(param_2 + 0x18) = 0;
  *(u32 *)(param_2 + 0x80) = 0;
  param_2[0x85] = 0;
  param_2[0x87] = 0;
  *(u32 *)(param_2 + 0x88) = 0;
  *(u32 *)(param_2 + 0x90) = 0;
  if (D_01e2be1c != (u8 *)0x0) {
    *(u8 **)((int)D_01e2be1c + 0x94) = param_2;
    *(u32 *)(param_2 + 0x94) = 0;
    D_01e2be1c = param_2;
    return;
  }
  D_01e2be18 = param_2;
  D_01e2be1c = param_2;
  *(u32 *)(param_2 + 0x94) = 0;
  return;
}

void func_002cd260(int param_1)

{
  f32 uVar1;
  
  if (*(char *)(param_1 + 0x87) != '\0') {
    *(u32 *)(param_1 + 0x18) = 0;
    *(u32 *)(param_1 + 0x88) = 0;
    uVar1 = D_003758ec;
    *(u32 *)(param_1 + 4) = 0;
*(f32*)(param_1 + 0x1c) = uVar1;
    *(u32 *)(param_1 + 8) = 0;
  }
  return;
}
