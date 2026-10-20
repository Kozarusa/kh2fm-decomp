#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" s64 func_00101698(...);
extern "C" int func_00192b30(...);
extern "C" int func_00192c90(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00303c18(...);
extern "C" u64 func_00303c48(...);
extern "C" u32 func_00303fc0(...);
extern "C" u32 func_00303ff8(...);
extern "C" u32 func_00316e20(...);
extern "C" u32 func_00316e88(...);
extern "C" u32 func_00316f38(...);
extern "C" u32 func_00316fc8(...);
extern "C" u32 func_00317140(...);
extern "C" u32 func_00317868(...);
extern "C" u64 func_0031a9d8(...);

u64 func_00304200(u64 param_1,u64 param_2,u32 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  u32 *puVar3;
  u64 uVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = func_00303c48(param_1,param_2,*(u32 *)((param_3 & 3) * 4 + 0x377cfc),0);
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 != 0) {
    puVar1 = *(u32 **)((int)param_1 + 0x48);
    uVar4 = param_2;
    if (puVar1 == (u32 *)0x0) {
      puVar1 = (u32 *)func_00303fc0(param_1,0x271);
      *(u32 **)((int)param_1 + 0x48) = puVar1;
      *puVar1 = 0;
    }
    while( true ) {
      puVar3 = puVar1;
      uVar2 = param_3 & 1;
      param_3 = (int)param_3 >> 1;
      param_2 = uVar4;
      if (uVar2 != 0) {
        param_2 = func_00303ff8(param_1,uVar4,puVar3);
        func_00303c18(param_1,uVar4);
      }
      if (param_3 == 0) break;
      uVar4 = param_2;
      puVar1 = (u32 *)*puVar3;
      if ((u32 *)*puVar3 == (u32 *)0x0) {
        puVar1 = (u32 *)func_00303ff8(param_1,puVar3,puVar3);
        *puVar3 = puVar1;
        *puVar1 = 0;
      }
    }
  }
  return param_2;
}

u32 func_00317d80(u64 param_1,u64 param_2)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  s64 lVar4;
  u64 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int aiStack_50 [4];
  
  func_002fde18(param_2,0,0xb50);
  iVar6 = (int)param_1;
  *(u64 *)(iVar6 + 0x2e0) = 0;
  *(u32 *)(iVar6 + 0x2cc) = 0;
  lVar4 = func_00101698(*(int *)(iVar6 + 0x2c8) + -1,iVar6 + 0x2d0);
  uVar2 = 5;
  if (lVar4 != 0) {
    piVar10 = (int *)lVar4;
    iVar3 = piVar10[1];
    iVar7 = (int)piVar10 + (4 - iVar3);
    iVar9 = (int)param_2;
    *(u32 *)(iVar9 + 0xb30) = *(u32 *)(iVar6 + 0x2d8);
    lVar4 = func_00317140(iVar7,param_1,param_2);
    uVar2 = 3;
    if (lVar4 != 0) {
      iVar8 = 0;
      func_00317868(lVar4,iVar7 + *(int *)((int)piVar10 + (4 - iVar3)) + 4,param_1,param_2);
      iVar3 = func_00316e20(*(u8 *)(iVar9 + 0xb49));
      iVar3 = (int)piVar10 + iVar3 * 2 + 8;
      if (*(char *)(iVar9 + 0xb4b) != '\0') {
        iVar3 = func_00316f38(iVar3,aiStack_50);
        iVar8 = iVar3 + aiStack_50[0];
      }
      cVar1 = *(char *)(iVar9 + 0xb4a);
      if (cVar1 != -1) {
        uVar5 = func_00316e88(cVar1,param_1);
        iVar3 = func_00316fc8(cVar1,uVar5,iVar3,iVar6 + 0x2cc);
      }
      if (iVar8 == 0) {
        iVar8 = iVar3;
      }
      func_00317868(iVar8,(int)piVar10 + *piVar10 + 4,param_1,param_2);
      uVar2 = 0;
    }
  }
  return uVar2;
}

void func_00319a60(u32 *param_1)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = 0xf;
  puVar2 = param_1;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  param_1[0x10] = 0;
  puVar2 = param_1 + 0x11;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  param_1[0x21] = 0;
  puVar2 = param_1 + 0x22;
  iVar1 = 2;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x25;
  iVar1 = 5;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x2b;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  puVar2 = param_1 + 0x3b;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x4b;
  iVar1 = 3;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  param_1[0x4f] = 0;
  puVar2 = param_1 + 0x51;
  param_1[0x50] = 0;
  iVar1 = 9;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  } while (iVar1 != -1);
  puVar2 = param_1 + 0x65;
  iVar1 = 9;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  } while (iVar1 != -1);
  *(u16 *)((int)param_1 + 0x1e6) = 0;
  *(u16 *)(param_1 + 0x79) = 0;
  return;
}

void func_00319bd0(int param_1)

{
  int iVar1;
  u16 *puVar2;
  u32 *puVar3;
  int iVar4;
  u16 *puVar5;
  u32 *puVar6;
  
  iVar1 = 0x12;
  puVar2 = (u16 *)(param_1 + 4);
  do {
    iVar4 = 0x3f;
    puVar5 = puVar2;
    do {
      *puVar5 = 0;
      iVar4 = iVar4 + -1;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5 = puVar5 + 3;
    } while (iVar4 != -1);
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 0xc0;
  } while (iVar1 != -1);
  puVar3 = (u32 *)(param_1 + 0x1c84);
  iVar1 = 0x12;
  do {
    iVar4 = 7;
    puVar6 = puVar3;
    do {
      *puVar6 = 0;
      iVar4 = iVar4 + -1;
      puVar6 = puVar6 + 1;
    } while (-1 < iVar4);
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 8;
  } while (iVar1 != -1);
  *(u32 *)(param_1 + 0x1ee4) = 0;
  puVar3 = (u32 *)(param_1 + 0x22ec);
  *(u32 *)(param_1 + 0x1ee8) = 0;
  iVar1 = 0x12;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
  } while (iVar1 != -1);
  puVar3 = (u32 *)(param_1 + 0x2384);
  iVar1 = 6;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar1);
  puVar3 = (u32 *)(param_1 + 0x23a0);
  iVar1 = 0xf;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar1);
  puVar3 = (u32 *)(param_1 + 0x23f4);
  iVar1 = 0xf;
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (-1 < iVar1);
  *(u32 *)(param_1 + 0x2490) = 0;
  iVar1 = 9;
  puVar3 = (u32 *)(param_1 + 0x2494);
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3[1] = 0;
    puVar3 = puVar3 + 2;
  } while (iVar1 != -1);
  return;
}

void func_00319e90(u32 *param_1,u32 *param_2)

{
  u16 uVar1;
  u16 uVar2;
  u16 uVar3;
  u16 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  
  uVar5 = param_2[1];
  uVar6 = param_2[2];
  uVar7 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar5;
  param_1[2] = uVar6;
  param_1[3] = uVar7;
  uVar5 = param_2[5];
  uVar6 = param_2[6];
  uVar7 = param_2[7];
  param_1[4] = param_2[4];
  param_1[5] = uVar5;
  param_1[6] = uVar6;
  param_1[7] = uVar7;
  uVar5 = param_2[9];
  uVar6 = param_2[10];
  uVar7 = param_2[0xb];
  param_1[8] = param_2[8];
  param_1[9] = uVar5;
  param_1[10] = uVar6;
  param_1[0xb] = uVar7;
  uVar5 = param_2[0xd];
  uVar6 = param_2[0xe];
  uVar7 = param_2[0xf];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = uVar5;
  param_1[0xe] = uVar6;
  param_1[0xf] = uVar7;
  uVar5 = param_2[0x11];
  uVar6 = param_2[0x12];
  uVar7 = param_2[0x13];
  param_1[0x10] = param_2[0x10];
  param_1[0x11] = uVar5;
  param_1[0x12] = uVar6;
  param_1[0x13] = uVar7;
  uVar5 = param_2[0x15];
  uVar6 = param_2[0x16];
  uVar7 = param_2[0x17];
  param_1[0x14] = param_2[0x14];
  param_1[0x15] = uVar5;
  param_1[0x16] = uVar6;
  param_1[0x17] = uVar7;
  uVar1 = *(u16 *)((int)param_2 + 0x62);
  uVar2 = *(u16 *)(param_2 + 0x19);
  uVar3 = *(u16 *)(param_2 + 0x18);
  uVar4 = *(u16 *)((int)param_2 + 0x66);
  uVar5 = param_2[0x1b];
  param_1[0x1a] = param_2[0x1a];
  *(u16 *)(param_1 + 0x18) = uVar3;
  *(u16 *)((int)param_1 + 0x62) = uVar1;
  *(u16 *)(param_1 + 0x19) = uVar2;
  *(u16 *)((int)param_1 + 0x66) = uVar4;
  param_1[0x1b] = uVar5;
  param_1[0x1c] = param_2[0x1c];
  param_1[0x1d] = param_2[0x1d];
  uVar5 = param_2[0x1e];
  uVar6 = param_2[0x1f];
  param_1[0x20] = param_2[0x20];
  param_1[0x1e] = uVar5;
  param_1[0x1f] = uVar6;
  return;
}

u64 func_0031a850(u64 param_1,int param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  u32 uVar16;
  
  func_0031a9d8();
  uVar1 = *(u32 *)(param_2 + 0xb4);
  iVar7 = (int)param_1;
  *(u32 *)(iVar7 + 0xb0) = *(u32 *)(param_2 + 0xb0);
  *(u32 *)(iVar7 + 0xb4) = uVar1;
  *(u32 *)(iVar7 + 0xb8) = *(u32 *)(param_2 + 0xb8);
  *(u32 *)(iVar7 + 0xbc) = *(u32 *)(param_2 + 0xbc);
  *(u32 *)(iVar7 + 0xc0) = *(u32 *)(param_2 + 0xc0);
  *(u32 *)(iVar7 + 0xc4) = *(u32 *)(param_2 + 0xc4);
  *(u32 *)(iVar7 + 200) = *(u32 *)(param_2 + 200);
  *(u32 *)(iVar7 + 0xcc) = *(u32 *)(param_2 + 0xcc);
  *(u32 *)(iVar7 + 0xd0) = *(u32 *)(param_2 + 0xd0);
  *(u32 *)(iVar7 + 0xd4) = *(u32 *)(param_2 + 0xd4);
  *(u32 *)(iVar7 + 0xd8) = *(u32 *)(param_2 + 0xd8);
  *(u32 *)(iVar7 + 0xdc) = *(u32 *)(param_2 + 0xdc);
  *(u32 *)(iVar7 + 0xe0) = *(u32 *)(param_2 + 0xe0);
  *(u32 *)(iVar7 + 0xe4) = *(u32 *)(param_2 + 0xe4);
  *(u32 *)(iVar7 + 0xe8) = *(u32 *)(param_2 + 0xe8);
  uVar1 = *(u32 *)(param_2 + 0xf0);
  *(u32 *)(iVar7 + 0xec) = *(u32 *)(param_2 + 0xec);
  *(u32 *)(iVar7 + 0xf0) = uVar1;
  uVar1 = *(u32 *)(param_2 + 0xf4);
  uVar2 = *(u32 *)(param_2 + 0xf8);
  uVar3 = *(u32 *)(param_2 + 0xfc);
  uVar8 = *(u32 *)(param_2 + 0x104);
  uVar10 = *(u32 *)(param_2 + 0x108);
  uVar4 = *(u32 *)(param_2 + 0x10c);
  uVar5 = *(u32 *)(param_2 + 0x110);
  uVar6 = *(u32 *)(param_2 + 0x114);
  uVar9 = *(u32 *)(param_2 + 0x118);
  uVar12 = *(u32 *)(param_2 + 0x11c);
  uVar11 = *(u32 *)(param_2 + 0x120);
  uVar14 = *(u32 *)(param_2 + 0x124);
  uVar13 = *(u32 *)(param_2 + 0x128);
  uVar16 = *(u32 *)(param_2 + 300);
  uVar15 = *(u32 *)(param_2 + 0x130);
  *(u32 *)(iVar7 + 0x100) = *(u32 *)(param_2 + 0x100);
  *(u32 *)(iVar7 + 0xf4) = uVar1;
  *(u32 *)(iVar7 + 0xf8) = uVar2;
  *(u32 *)(iVar7 + 0xfc) = uVar3;
  *(u32 *)(iVar7 + 0x104) = uVar8;
  *(u32 *)(iVar7 + 0x108) = uVar10;
  *(u32 *)(iVar7 + 0x10c) = uVar4;
  *(u32 *)(iVar7 + 0x110) = uVar5;
  *(u32 *)(iVar7 + 0x114) = uVar6;
  *(u32 *)(iVar7 + 0x118) = uVar9;
  *(u32 *)(iVar7 + 0x11c) = uVar12;
  *(u32 *)(iVar7 + 0x120) = uVar11;
  *(u32 *)(iVar7 + 0x124) = uVar14;
  *(u32 *)(iVar7 + 0x128) = uVar13;
  *(u32 *)(iVar7 + 300) = uVar16;
  *(u32 *)(iVar7 + 0x130) = uVar15;
  *(u32 *)(iVar7 + 0x134) = *(u32 *)(param_2 + 0x134);
  uVar1 = *(u32 *)(param_2 + 0x154);
  uVar8 = *(u32 *)(param_2 + 0x13c);
  uVar2 = *(u32 *)(param_2 + 0x140);
  uVar3 = *(u32 *)(param_2 + 0x144);
  uVar4 = *(u32 *)(param_2 + 0x148);
  uVar5 = *(u32 *)(param_2 + 0x14c);
  uVar6 = *(u32 *)(param_2 + 0x150);
  *(u32 *)(iVar7 + 0x138) = *(u32 *)(param_2 + 0x138);
  *(u32 *)(iVar7 + 0x13c) = uVar8;
  *(u32 *)(iVar7 + 0x140) = uVar2;
  *(u32 *)(iVar7 + 0x144) = uVar3;
  *(u32 *)(iVar7 + 0x148) = uVar4;
  *(u32 *)(iVar7 + 0x14c) = uVar5;
  *(u32 *)(iVar7 + 0x150) = uVar6;
  *(u32 *)(iVar7 + 0x154) = uVar1;
  return param_1;
}

void func_0031cc30(int param_1,u32 param_2,u32 param_3,u64 param_4,s64 param_5,
                 u32 param_6,u32 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0xc);
  iVar1 = iVar5 + 1;
  iVar3 = iVar5 - *(int *)(param_1 + 0x10);
  iVar2 = iVar3 + 0x10;
  iVar4 = iVar5 + 0x10;
  if (-1 < iVar1) {
    iVar4 = iVar1;
  }
  iVar3 = iVar3 + 0x1f;
  if (-1 < iVar2) {
    iVar3 = iVar2;
  }
  if (iVar2 + (iVar3 >> 4) * -0x10 < 0xf) {
    *(int *)(param_1 + 0xc) = iVar1 + (iVar4 >> 4) * -0x10;
    iVar5 = param_1 + 0xc + iVar5 * 600;
    func_00192c90(param_4,iVar5 + 0x1e0);
    func_00192b30(param_4);
    if (param_5 != 0) {
      func_00192c90(param_5,iVar5 + 0x220);
      func_00192b30(param_5);
    }
    *(u32 *)(iVar5 + 0x1dc) = param_7;
    *(u32 *)(iVar5 + 0x1d0) = param_3;
    *(int *)(iVar5 + 0x1cc) = (int)param_5;
    *(u32 *)(iVar5 + 0x1d4) = param_2;
    *(u32 *)(iVar5 + 0x1d8) = param_6;
  }
  return;
}
