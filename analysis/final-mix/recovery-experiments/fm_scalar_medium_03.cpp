#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_001050c8(...);
extern "C" u64 func_001063f0(...);
extern "C" u64 func_00168aa0(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016bd60(...);
extern "C" u64 func_0017c430(...);
extern "C" u64 func_0017f488(...);
extern "C" u64 func_0019c090(...);
extern "C" u64 func_001c0cd8(...);
extern "C" u64 func_001db888(...);
extern "C" u64 func_002e34c8(...);
extern "C" u64 func_002e34d8(...);
extern "C" u64 func_002e3f58(...);
extern "C" u64 func_002e64b0(...);
extern "C" u64 func_002e64b8(...);
extern "C" u64 func_002e6ab0(...);
extern "C" u64 func_002eaf40(...);
extern "C" u64 func_002ed558(...);
extern "C" u64 func_002ed5a8(...);
extern "C" u64 func_002f3c28(...);
extern "C" u64 func_002f3d50(...);
extern "C" u64 func_002f3d98(...);
extern "C" u64 func_002f3dd8(...);
extern "C" u64 func_002f3e20(...);
extern "C" u64 func_002f3f40(...);
extern "C" u64 func_002f3f58(...);
extern "C" u64 func_002f4000(...);
extern "C" u64 func_002fd220(...);
extern "C" u64 func_002fd680(...);
extern "C" u64 func_002fde18(...);
extern "C" u64 func_002feac0(...);
extern "C" u64 func_002ffd00(...);
extern "C" u64 func_00302b18(...);
extern "C" u64 func_00306698(...);
extern "C" u64 func_003080d0(...);
extern "C" u64 func_003088f8(...);
extern "C" u64 func_00308dc0(...);
extern "C" u64 func_00308df0(...);
extern "C" u64 func_00309178(...);
extern "C" u64 func_003094b8(...);
extern "C" u64 func_0030a8f8(...);
extern "C" u64 func_0030ab88(...);
extern "C" u64 func_0030af40(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_00310b70(...);
extern "C" u64 func_00312db8(...);
extern "C" u64 func_00313e80(...);
extern "C" u64 func_00313f40(...);
extern "C" u64 func_00314330(...);
extern "C" u64 func_003144b0(...);
extern "C" u64 func_00314640(...);
extern "C" u64 func_003147a0(...);
extern "C" u64 func_00314a50(...);
extern "C" u64 func_00314b00(...);
extern "C" u64 func_00314b90(...);
extern "C" u64 func_00316e10(...);
extern "C" u64 func_00317128(...);
extern "C" u64 func_00317d80(...);
extern "C" u64 func_00319d30(...);
extern "C" u64 func_0031a850(...);

void func_002e2728(int param_1,s64 param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x110) == 0) {
    *(int *)(param_1 + 0x100) = (int)param_2;
    if (-1 < param_2) {
      func_002e34c8(param_1 + 0x68);
    }
    piVar1 = (int *)func_002e34d8(param_1 + 0x68,*(u32 *)(param_1 + 0x100));
    *(int **)(param_1 + 100) = piVar1;
    if (param_3 == '\0') {
      iVar4 = piVar1[1];
    }
    else {
      iVar4 = *piVar1;
    }
    uVar3 = 1;
    iVar2 = *(int *)(param_1 + 0x100) + 1;
    if (param_3 == '\0') {
      uVar3 = 2;
      iVar2 = *(int *)(param_1 + 0x100);
    }
    *(u32 *)(param_1 + 0x110) = uVar3;
    *(float *)(param_1 + 0x104) = (float)iVar4;
    *(int *)(param_1 + 0x108) = iVar2;
  }
  return;
}

int func_002e3318(int param_1,int param_2,int param_3,u64 param_4,u64 param_5,u64 param_6)

{
  u16 uVar1;
  u32 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u8 *pbVar7;
  u8 *pbVar8;
  int iVar9;
  
  iVar5 = *(int *)(param_1 + 8);
  iVar9 = 0;
  if (iVar5 != 0) {
    pbVar7 = (u8 *)(param_1 + 0x10);
    iVar4 = 0;
    iVar9 = 0;
    if (0 < iVar5) {
      do {
        uVar6 = (u32)*(u16 *)(pbVar7 + 2);
        if (((*pbVar7 == param_5) && (pbVar7[1] == param_6)) && (iVar3 = 0, uVar6 != 0)) {
          puVar2 = (u32 *)(iVar9 * 4 + param_2);
          uVar1 = *(u16 *)(pbVar7 + 4);
          pbVar8 = pbVar7;
          while( true ) {
            if ((uVar1 == param_4) && (iVar9 < param_3)) {
              iVar9 = iVar9 + 1;
              *puVar2 = *(u32 *)(pbVar8 + 8);
              uVar6 = (u32)*(u16 *)(pbVar7 + 2);
              puVar2 = puVar2 + 1;
            }
            iVar3 = iVar3 + 1;
            if ((int)uVar6 <= iVar3) break;
            uVar1 = *(u16 *)(pbVar8 + 0xc);
            pbVar8 = pbVar8 + 8;
          }
          iVar5 = *(int *)(param_1 + 8);
        }
        iVar4 = iVar4 + 1;
        pbVar7 = pbVar7 + uVar6 * 8 + 4;
      } while (iVar4 < iVar5);
    }
  }
  return iVar9;
}

u64 func_002e46d0(u64 param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  func_002e3f58();
  fVar6 = *param_2;
  fVar9 = *param_3;
  fVar5 = param_3[1];
  fVar3 = param_2[1];
  fVar7 = param_2[2];
  fVar8 = param_3[2];
  pfVar1 = (float *)param_1;
  pfVar1[3] = param_2[3] * param_3[3] - (fVar7 * fVar8 + fVar3 * fVar5 + fVar6 * fVar9);
  fVar4 = param_2[3];
  fVar2 = param_3[3];
  *pfVar1 = fVar2 * fVar6 + fVar4 * fVar9 + (fVar3 * fVar8 - fVar7 * fVar5);
  fVar6 = *param_3;
  fVar9 = *param_2;
  pfVar1[1] = fVar2 * fVar3 + fVar4 * fVar5 + (fVar7 * fVar6 - fVar9 * fVar8);
  pfVar1[2] = fVar2 * fVar7 + fVar4 * fVar8 + (fVar9 * param_3[1] - param_2[1] * fVar6);
  return param_1;
}

void func_002e6fc0(u32 *param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  u64 uVar3;
  int iVar4;
  
  *param_1 = (int)param_2;
  param_1[1] = 0;
  lVar2 = func_002e64b0(param_2);
  iVar4 = (int)lVar2;
  param_1[2] = iVar4;
  uVar3 = func_001050c8();
  iVar1 = func_001063f0(iVar4 * 0x40 + 0x10,uVar3);
  *(int *)(iVar1 + 0xc) = iVar4;
  if (lVar2 != 0) {
    for (iVar4 = iVar4 + -2; iVar4 != -1; iVar4 = iVar4 + -1) {
    }
  }
  param_1[1] = iVar1 + 0x10;
  return;
}

void func_002e7108(u32 param_1,u32 *param_2)

{
  int iVar1;
  u64 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_2[2];
  if (0 < iVar1) {
    iVar3 = param_2[1];
    iVar4 = 0;
    while( true ) {
      uVar2 = func_002e64b8(iVar4,*param_2);
      func_002e6ab0(param_1,uVar2,iVar3 + iVar4 * 0x40);
      if (iVar1 <= iVar4 + 1) break;
      iVar3 = param_2[1];
      iVar4 = iVar4 + 1;
    }
  }
  return;
}

u32 func_002eb3b8(u64 param_1)

{
  u64 uVar1;
  s64 lVar2;
  u32 uVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  uVar1 = func_002eaf40();
  uVar3 = 0;
  if ((*(u32 *)(iVar4 + 0x160) & 0x4000) != 0) {
    lVar2 = func_001c0cd8(uVar1);
    if (lVar2 != 0) {
      return 0;
    }
    uVar3 = *(u32 *)(iVar4 + 0x160) & 0x4000;
  }
  if (uVar3 != 0) {
    func_0017f488(0,0,iVar4 + 0x140,0);
  }
  lVar2 = func_0019c090(param_1);
  if (lVar2 != 0) {
    func_0017c430(0,param_1,0);
  }
  func_0016bd60(param_1,lVar2 != 0);
  return 1;
}

u64
func_002ed350(u64 param_1,u64 param_2,u32 *param_3,u64 param_4,
            u64 *param_5)

{
  u64 uVar1;
  u64 uVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  
  uVar2 = 0;
  iVar5 = *(int *)((int)param_1 + 0x9f4);
  if (*(int *)(iVar5 + 0x1c) != 0) {
    uVar2 = func_001db888(iVar5 + 0x14,0x80);
    func_002ed558(uVar2,param_1,param_2,param_4,0x2ed8a0);
    iVar5 = (int)uVar2;
    *(u32 *)(iVar5 + 100) = *param_3;
    *(u32 *)(iVar5 + 0x68) = param_3[1];
    *(u32 *)(iVar5 + 0x6c) = param_3[2];
    *(u32 *)(iVar5 + 0x70) = param_3[3];
    *(u32 *)(iVar5 + 0x74) = param_3[4];
    if ((u64 *)(iVar5 + 0x40) != param_5) {
      uVar1 = *param_5;
      uVar3 = *(u32 *)(param_5 + 1);
      uVar4 = *(u32 *)((int)param_5 + 0xc);
      *(int *)(iVar5 + 0x40) = (int)uVar1;
      *(int *)(iVar5 + 0x44) = (int)((u64)uVar1 >> 0x20);
      *(u32 *)(iVar5 + 0x48) = uVar3;
      *(u32 *)(iVar5 + 0x4c) = uVar4;
    }
    func_002ed5a8(uVar2);
  }
  return uVar2;
}

u32 func_002f2020(void)

{
  char cVar1;
  u32 uVar2;
  s64 lVar3;
  char *pcVar4;
  u8 auStack_149 [9];
  char acStack_140 [256];
  
  pcVar4 = acStack_140;
  lVar3 = func_0030a8f8(0x3762c8,1);
  uVar2 = 0;
  if (lVar3 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    for (; uVar2 < 0x100; uVar2 = uVar2 + 1) {
      func_0030af40(lVar3,pcVar4,1);
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar1 == '\0') break;
    }
    func_0030ab88(lVar3);
    lVar3 = func_002fd220(auStack_149 + uVar2);
    uVar2 = (u32)(0x1315670 < lVar3);
  }
  return uVar2;
}

void func_002f3500(u64 param_1,u32 param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = 0x1000000;
  if (param_3 != 0) {
    iVar2 = param_3;
  }
  uVar1 = *(u32 *)((int)param_1 + 0x10);
  while (uVar1 < param_2) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      func_003080d0(0x3767d0);
      func_002f3c28(param_1);
    }
    uVar1 = *(u32 *)((int)param_1 + 0x10);
  }
  return;
}

void func_002f4310(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  u8 auStack_90 [32];
  u8 auStack_70 [16];
  
  func_002f4000(auStack_b0);
  func_002f3d50(auStack_70,param_4,param_3);
  func_002f3d98(auStack_b0,auStack_70);
  func_002f3d98(auStack_90,param_3);
  func_002f3d50(auStack_a0,auStack_90,auStack_b0);
  func_002f3f58(auStack_b0,auStack_b0,param_2);
  func_002f3e20(param_1,auStack_b0);
  return;
}

void func_002f43c0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  u8 auStack_60 [16];
  
  func_002f3f40(0xbf800000,auStack_60);
  func_002f3d98(param_1,auStack_60);
  func_002f3f40(0xbf800000,auStack_60,param_3);
  iVar1 = (int)param_1;
  func_002f3d98(iVar1 + 0x10,auStack_60);
  func_002f3f40(0xbf800000,auStack_60,param_4);
  func_002f3d98(iVar1 + 0x20,auStack_60);
  *(u32 *)(iVar1 + 0x30) = 0;
  *(u32 *)(iVar1 + 0x3c) = 0x3f800000;
  *(u32 *)(iVar1 + 0x38) = 0;
  *(u32 *)(iVar1 + 0x34) = 0;
  func_002f3dd8(param_1,param_1);
  return;
}

u32 func_002f6440(u8 *param_1,u32 *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = 0;
  uVar2 = 0;
  iVar1 = 0;
  do {
    if (((int)(u32)*param_1 >> (uVar3 & 0x1f) & 1U) == 0) {
      *param_2 = 0;
      param_2[2] = 0;
      param_2[3] = 0;
    }
    else {
      *param_2 = 1;
      param_2[2] = iVar4;
      param_2[3] = uVar2;
      if ((iVar1 - 0x10U < 0x10) || (iVar1 - 0x23U < 4)) {
        param_2[1] = 8;
        iVar4 = iVar4 + 1;
      }
      else {
        uVar2 = uVar2 + 1;
        param_2[1] = 1;
        if ((uVar2 & 7) == 0) {
          iVar4 = iVar4 + 1;
          uVar2 = 0;
        }
      }
    }
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 1;
    if ((uVar3 & 7) == 0) {
      param_1 = param_1 + 1;
      uVar3 = 0;
    }
    param_2 = param_2 + 4;
  } while (iVar1 < 0x28);
  return 1;
}

u64 * func_002fdd68(u64 *param_1,u64 *param_2,u32 param_3)

{
  u8 uVar1;
  u64 uVar2;
  u32 uVar3;
  u32 uVar4;
  u64 *puVar5;
  
  puVar5 = param_1;
  if ((0x1f < param_3) && ((((u32)param_2 | (u32)param_1) & 0xf) == 0)) {
    do {
      uVar2 = *param_2;
      uVar3 = *(u32 *)(param_2 + 1);
      uVar4 = *(u32 *)((int)param_2 + 0xc);
      param_3 = param_3 - 0x20;
      *(int *)puVar5 = (int)uVar2;
      *(int *)((int)puVar5 + 4) = (int)((u64)uVar2 >> 0x20);
      *(u32 *)(puVar5 + 1) = uVar3;
      *(u32 *)((int)puVar5 + 0xc) = uVar4;
      uVar2 = param_2[2];
      uVar3 = *(u32 *)(param_2 + 3);
      uVar4 = *(u32 *)((int)param_2 + 0x1c);
      param_2 = param_2 + 4;
      *(int *)(puVar5 + 2) = (int)uVar2;
      *(int *)((int)puVar5 + 0x14) = (int)((u64)uVar2 >> 0x20);
      *(u32 *)(puVar5 + 3) = uVar3;
      *(u32 *)((int)puVar5 + 0x1c) = uVar4;
      puVar5 = puVar5 + 4;
    } while (0x1f < param_3);
    for (; 7 < param_3; param_3 = param_3 - 8) {
      uVar2 = *param_2;
      param_2 = param_2 + 1;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
    }
  }
  while (param_3 = param_3 - 1, param_3 != 0xffffffff) {
    uVar1 = *(u8 *)param_2;
    param_2 = (u64 *)((int)param_2 + 1);
    *(u8 *)puVar5 = uVar1;
    puVar5 = (u64 *)((int)puVar5 + 1);
  }
  return param_1;
}

u32 func_002feb28(u32 *param_1,u64 param_2,u32 param_3)

{
  s64 lVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  
  if (param_2 < 0x20) {
    iVar2 = param_1[0x75];
    if (iVar2 == 0) {
      lVar1 = func_002feac0();
      if (lVar1 != 0) {
        return 0xffffffff;
      }
      iVar2 = param_1[0x75];
    }
    puVar4 = (u32 *)((int)param_2 * 4 + iVar2);
    uVar3 = *puVar4;
    *puVar4 = param_3;
  }
  else {
    uVar3 = 0xffffffff;
    *param_1 = 0x16;
  }
  return uVar3;
}

s64 func_002ffc50(int param_1)

{
  s64 lVar1;
  s64 lVar2;
  u8 *apuStack_480 [2];
  u32 uStack_478;
  u16 uStack_474;
  u16 uStack_472;
  u8 *puStack_470;
  u32 uStack_46c;
  u32 uStack_468;
  u32 uStack_464;
  u32 uStack_45c;
  u32 uStack_42c;
  u8 auStack_420 [1024];
  
  apuStack_480[0] = auStack_420;
  uStack_42c = *(u32 *)(param_1 + 0x54);
  uStack_472 = *(u16 *)(param_1 + 0xe);
  uStack_474 = *(u16 *)(param_1 + 0xc) & 0xfffd;
  uStack_464 = *(u32 *)(param_1 + 0x1c);
  uStack_45c = *(u32 *)(param_1 + 0x24);
  uStack_46c = 0x400;
  uStack_478 = 0x400;
  uStack_468 = 0;
  puStack_470 = apuStack_480[0];
  lVar1 = func_002ffd00(apuStack_480);
  if ((-1 < lVar1) && (lVar2 = func_00302b18(apuStack_480), lVar2 != 0)) {
    lVar1 = -1;
  }
  if ((uStack_474 & 0x40) != 0) {
    *(u16 *)(param_1 + 0xc) = *(u16 *)(param_1 + 0xc) | 0x40;
  }
  return lVar1;
}

s64 func_00304fb0(u64 param_1,int param_2,int param_3)

{
  s64 lVar1;
  s64 lVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  lVar1 = func_002fd680(param_1,param_2 * param_3);
  lVar2 = 0;
  if (lVar1 != 0) {
    puVar5 = (u32 *)lVar1;
    uVar3 = (puVar5[-1] & 0xfffffffc) - 4;
    lVar2 = lVar1;
    if (uVar3 < 0x25) {
      puVar4 = puVar5;
      if (0x13 < uVar3) {
        *puVar5 = 0;
        puVar4 = puVar5 + 2;
        puVar5[1] = 0;
        if (0x1b < uVar3) {
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar4 = puVar5 + 4;
          if (0x23 < uVar3) {
            puVar5[4] = 0;
            puVar4 = puVar5 + 6;
            puVar5[5] = 0;
          }
        }
      }
      *puVar4 = 0;
      puVar4[2] = 0;
      puVar4[1] = 0;
    }
    else {
      func_002fde18(lVar1,0,uVar3);
    }
  }
  return lVar2;
}

int func_00306f68(u64 param_1)

{
  int iVar1;
  u64 uVar2;
  s64 lVar3;
  
  lVar3 = ((param_1 & 0x7fffffffffffffff) >> 0x34) - 0x433;
  if (lVar3 < -0x35) {
    return 0;
  }
  if (0xc < lVar3) {
    return 9999;
  }
  uVar2 = param_1 & 0xfffffffffffff | 0x10000000000000;
  if (lVar3 < 0) {
    uVar2 = uVar2 >> (s64)(-2 - (int)lVar3);
    if ((uVar2 & 3) == 3) {
      iVar1 = (int)(uVar2 >> 2) + 1;
    }
    else {
      iVar1 = (int)(uVar2 >> 2);
    }
  }
  else {
    iVar1 = (int)(uVar2 << (s64)(int)lVar3);
  }
  return iVar1;
}

int func_00308cf8(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  func_0030edb0();
  iVar1 = 0;
  iVar3 = param_1[1];
  if (0 < param_1[2]) {
    do {
      if ((*(u32 *)(iVar3 + 0x10) & 1) == 0) {
        *(u32 *)(iVar3 + 0x10) = iVar1 << 0x10 | 5;
        iVar1 = *param_1;
        iVar2 = iVar1 + 1;
        *param_1 = iVar2;
        if (iVar2 == 1) {
          iVar2 = 1;
          *param_1 = iVar1 + 2;
        }
        *(int *)(iVar3 + 0x14) = iVar3;
        *(int *)(iVar3 + 0x18) = iVar2;
        func_0030ee00();
        return iVar3;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar1 < param_1[2]);
  }
  func_0030ee00();
  return 0;
}

void func_00308f40(int param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  s64 lVar3;
  int iVar4;
  
  if ((*(u32 *)(param_1 + 0x10) & 4) == 0) {
    uVar2 = func_00308dc0(param_2);
  }
  else {
    uVar2 = func_00308df0(param_2,*(u32 *)(param_1 + 0x10) >> 0x10);
  }
  uVar1 = *(u32 *)(param_1 + 0x1c);
  iVar4 = (int)uVar2;
  *(u32 *)(iVar4 + 0x14) = *(u32 *)(param_1 + 0x14);
  *(u32 *)(iVar4 + 0x1c) = uVar1;
  *(u32 *)(iVar4 + 0x20) = 0x8000000c;
  *(u32 *)(iVar4 + 0x24) = *(u32 *)(param_1 + 0x20);
  *(u32 *)(iVar4 + 0x28) = *(u32 *)(param_1 + 0x24);
  *(u32 *)(iVar4 + 0x2c) = *(u32 *)(param_1 + 0x28);
  lVar3 = func_003088f8(0xffffffff80000008,uVar2,0x40,*(u32 *)(param_1 + 0x20),
                       *(u32 *)(param_1 + 0x24),*(u32 *)(param_1 + 0x28));
  if (lVar3 == 0) {
    func_00310b70(0x800,0x308f00,uVar2);
    return;
  }
  return;
}

void func_00309208(int param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  s64 lVar3;
  int iVar4;
  
  uVar2 = func_00308dc0(param_2);
  uVar1 = *(u32 *)(param_1 + 0x14);
  iVar4 = (int)uVar2;
  *(u32 *)(iVar4 + 0x1c) = *(u32 *)(param_1 + 0x1c);
  *(u32 *)(iVar4 + 0x14) = uVar1;
  *(u32 *)(iVar4 + 0x20) = 0x80000009;
  lVar3 = func_00309178(*(u32 *)(param_1 + 0x20),param_2);
  if (lVar3 == 0) {
    *(u32 *)(iVar4 + 0x24) = 0;
    *(u32 *)(iVar4 + 0x28) = 0;
  }
  else {
    *(int *)(iVar4 + 0x24) = (int)lVar3;
    *(u32 *)(iVar4 + 0x28) = *(u32 *)((int)lVar3 + 8);
  }
  lVar3 = func_003088f8(0xffffffff80000008,uVar2,0x40,0,0,0);
  if (lVar3 == 0) {
    func_00310b70(0x800,0x3091c8,uVar2);
    return;
  }
  return;
}

int func_00309d60(u32 param_1,u32 param_2,u64 param_3,u64 param_4,
                u64 param_5,u64 param_6,u64 param_7,u64 param_8,
                u64 param_9,int param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  while( true ) {
    iVar1 = func_003094b8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    iVar1 = -(iVar1 >> 0x1f);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_10 != 0) break;
    func_00306698(iVar2 * 1000);
    if (iVar2 < 0x7f) {
      iVar2 = iVar2 << 1;
    }
    iVar3 = iVar3 + 1;
    if (100 < iVar3) {
      return iVar1;
    }
  }
  return iVar1;
}

void func_003107e8(s64 param_1,s64 param_2,s64 param_3)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = func_00312db8(param_1,0x8ca0000);
  if (param_2 != 0) {
    *(u32 *)param_2 = uVar1;
  }
  if (param_3 != 0) {
    uVar2 = func_00312db8((param_1 -
                         ((s64)(int)((u64)uVar1 * 0x8ca0000 >> 0x20) << 0x20 |
                         (u64)uVar1 * 0x8ca0000 & 0xffffffff)) * 1000000,0x8ca0000);
    *(u32 *)param_3 = uVar2;
  }
  return;
}

void func_00311af0(u64 param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  if ((0x3ffffffffffffe < param_1 + 0x1fffffffffffff) && ((param_1 & 0x7ff) != 0)) {
    param_1 = param_1 | 0x800;
  }
  uVar1 = func_00314330((s64)param_1 >> 0x20);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar2 = func_00314330((int)param_1);
  if ((int)param_1 < 0) {
    uVar2 = func_00313e80(uVar2,0x41f0000000000000);
  }
  uVar1 = func_00313e80(uVar1,uVar2);
  func_003144b0(uVar1);
  return;
}

u32 func_00313bc0(u32 param_1)

{
  u32 uVar1;
  u32 uStack_30;
  int iStack_2c;
  int iStack_28;
  u32 uStack_24;
  u32 auStack_20 [4];
  
  auStack_20[0] = param_1;
  func_00314640(auStack_20,&uStack_30);
  uVar1 = 0;
  if ((((uStack_30 != 2) && (1 < uStack_30)) && (iStack_2c == 0)) &&
     (uVar1 = 0xffffffff, uStack_30 != 4)) {
    uVar1 = 0;
    if ((-1 < iStack_28) && (uVar1 = 0xffffffff, iStack_28 < 0x20)) {
      if (iStack_28 < 0x1f) {
        uVar1 = uStack_24 >> (0x1eU - iStack_28 & 0x1f);
      }
      else {
        uVar1 = uStack_24 << (iStack_28 - 0x1eU & 0x1f);
      }
    }
  }
  return uVar1;
}

u64 func_003141e8(u64 param_1,u64 param_2)

{
  u32 uVar1;
  u32 uVar2;
  bool bVar3;
  u64 uVar4;
  u32 *puVar5;
  u32 *puVar6;
  u64 uVar7;
  u64 uVar8;
  u64 uVar9;
  u64 uVar10;
  
  puVar5 = (u32 *)param_1;
  uVar1 = *puVar5;
  uVar4 = param_1;
  if (1 < uVar1) {
    puVar6 = (u32 *)param_2;
    uVar2 = *puVar6;
    uVar4 = param_2;
    if (1 < uVar2) {
      puVar5[1] = puVar5[1] ^ puVar6[1];
      if ((uVar1 == 4) || (uVar1 == 2)) {
        if (uVar1 == uVar2) {
          return 0x378498;
        }
        return param_1;
      }
      if (uVar2 == 4) {
        puVar5[4] = 0;
        puVar5[5] = 0;
        puVar5[2] = 0;
        return param_1;
      }
      if (uVar2 == 2) {
        *puVar5 = 4;
        return param_1;
      }
      uVar1 = puVar6[2];
      uVar2 = puVar5[2];
      uVar7 = *(u64 *)(puVar6 + 4);
      uVar9 = *(u64 *)(puVar5 + 4);
      puVar5[2] = uVar2 - uVar1;
      bVar3 = false;
      if (uVar9 < uVar7) {
        uVar9 = uVar9 << 1;
        puVar5[2] = (uVar2 - uVar1) - 1;
        bVar3 = uVar9 < uVar7;
      }
      uVar8 = 0;
      uVar10 = 0x1000000000000000;
      do {
        if (bVar3) {
          uVar9 = uVar9 << 1;
        }
        else {
          uVar8 = uVar8 | uVar10;
          uVar9 = (uVar9 - uVar7) * 2;
        }
        uVar10 = uVar10 >> 1;
        bVar3 = uVar9 < uVar7;
      } while (uVar10 != 0);
      *(u64 *)(puVar5 + 4) = uVar8;
      uVar4 = param_1;
    }
  }
  return uVar4;
}

int func_003143e0(u64 param_1)

{
  int iVar1;
  u32 uStack_40;
  int iStack_3c;
  int iStack_38;
  u64 uStack_30;
  u64 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  if (uStack_40 == 2) {
    return 0;
  }
  if (uStack_40 < 2) {
    return 0;
  }
  if (uStack_40 != 4) {
    if (iStack_38 < 0) {
      return 0;
    }
    if (iStack_38 < 0x1f) {
      iVar1 = (int)(uStack_30 >> (s64)(0x3c - iStack_38));
      if (iStack_3c == 0) {
        return iVar1;
      }
      return -iVar1;
    }
  }
  iVar1 = -0x80000000;
  if (iStack_3c == 0) {
    iVar1 = 0x7fffffff;
  }
  return iVar1;
}

u32 func_00314508(u64 param_1)

{
  u32 uVar1;
  u32 uStack_40;
  int iStack_3c;
  int iStack_38;
  u64 uStack_30;
  u64 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  uVar1 = 0;
  if ((((uStack_40 != 2) && (1 < uStack_40)) && (iStack_3c == 0)) &&
     (uVar1 = 0xffffffff, uStack_40 != 4)) {
    uVar1 = 0;
    if ((-1 < iStack_38) && (uVar1 = 0xffffffff, iStack_38 < 0x20)) {
      if (iStack_38 < 0x3d) {
        uVar1 = (u32)(uStack_30 >> (s64)(0x3c - iStack_38));
      }
      else {
        uVar1 = (u32)(uStack_30 << (s64)(iStack_38 + -0x3c));
      }
    }
  }
  return uVar1;
}

void func_003145a8(s64 param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  uVar1 = func_00314330(param_1 >> 0x20);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar1 = func_00313f40(uVar1,0x40f0000000000000);
  uVar2 = func_00314330((int)param_1);
  if ((int)param_1 < 0) {
    uVar2 = func_00313e80(uVar2,0x41f0000000000000);
  }
  func_00313e80(uVar1,uVar2);
  return;
}

void func_00314ce8(s64 param_1,char *param_2,u32 *param_3)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  u64 uVar4;
  int aiStack_40 [4];
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = func_00317128();
  }
  *param_3 = uVar2;
  cVar1 = *param_2;
  param_2 = param_2 + 1;
  if (cVar1 == -1) {
    param_3[1] = uVar2;
  }
  else {
    uVar4 = func_00314a50(cVar1,param_1);
    param_2 = (char *)func_00314b90(cVar1,uVar4,param_2,param_3 + 1);
  }
  cVar1 = *param_2;
  param_2 = param_2 + 1;
  *(char *)(param_3 + 5) = cVar1;
  if (cVar1 == -1) {
    param_3[3] = 0;
  }
  else {
    param_2 = (char *)func_00314b00(param_2,aiStack_40);
    param_3[3] = param_2 + aiStack_40[0];
  }
  *(char *)((int)param_3 + 0x15) = *param_2;
  iVar3 = func_00314b00(param_2 + 1,aiStack_40);
  param_3[4] = iVar3 + aiStack_40[0];
  return;
}

u32 func_00316c68(int *param_1,s64 param_2)

{
  int *piVar1;
  s64 lVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar1 = (int *)func_00316e10();
  lVar2 = func_0030edb0();
  while ((*piVar1 != 0 || (param_2 == 0))) {
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 1;
    if (7 < iVar3) {
      if (lVar2 != 0) {
        func_0030ee00();
      }
      return 0xffffffff;
    }
  }
  *piVar1 = 1;
  if (lVar2 != 0) {
    func_0030ee00();
  }
  *param_1 = iVar3;
  return 0;
}

u64 func_00317ee8(int param_1,u64 param_2)

{
  char cVar1;
  s64 lVar2;
  int iVar3;
  u64 uVar4;
  u8 *puVar5;
  u64 *puVar6;
  char *pcVar7;
  int iVar8;
  u8 auStack_e60 [712];
  int iStack_b98;
  u64 uStack_b80;
  u8 auStack_b70 [2840];
  u64 uStack_58;
  u16 uStack_50;
  int iStack_44;
  u8 bStack_28;
  u32 uStack_24;
  
  puVar5 = auStack_e60;
  func_002fde18(auStack_e60,0,0x2e8);
  iStack_b98 = param_1 + 1;
  lVar2 = func_00317d80(auStack_e60,auStack_b70);
  uVar4 = 0;
  if (lVar2 == 0) {
    iVar8 = (int)param_2;
    puVar6 = (u64 *)(iVar8 + 0x18);
    if (iStack_44 != 2) {
      pcVar7 = (char *)(iVar8 + 0x5a4);
      iVar3 = 0xb0;
      do {
        cVar1 = puVar5[0x2f8];
        *pcVar7 = cVar1;
        if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
          *puVar6 = *(u64 *)(puVar5 + 0x2f0);
        }
        else {
          *puVar6 = 0;
        }
        puVar6 = puVar6 + 1;
        pcVar7 = pcVar7 + 1;
        iVar3 = iVar3 + -1;
        puVar5 = puVar5 + 0x10;
      } while (-1 < iVar3);
      *(u16 *)(iVar8 + 0x5a0) = uStack_50;
      *(u64 *)(iVar8 + 8) = uStack_58;
      *(u16 *)(iVar8 + 0x5a2) = (u16)bStack_28;
      *(u64 *)(iVar8 + 0x10) = uStack_b80;
      *(u32 *)(iVar8 + 4) = uStack_24;
      uVar4 = param_2;
    }
  }
  return uVar4;
}

void func_00319870(u8 *param_1)

{
  u32 *puVar1;
  int iVar2;
  u8 *puVar3;
  
  iVar2 = 0x12;
  puVar3 = param_1;
  do {
    *puVar3 = 0;
    iVar2 = iVar2 + -1;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3 = puVar3 + 4;
  } while (iVar2 != -1);
  puVar1 = (u32 *)(param_1 + 0x4c);
  iVar2 = 7;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  param_1[0x16b] = 0;
  puVar3 = param_1 + 0x16c;
  iVar2 = 0x1f;
  do {
    *puVar3 = 0;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != -1);
  puVar1 = (u32 *)(param_1 + 0x18c);
  iVar2 = 3;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  func_00319d30(param_1 + 0x19c);
  return;
}

u64 func_0031a1a0(u64 param_1,int param_2)

{
  u8 uVar1;
  u8 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  u32 uVar11;
  
  iVar10 = (int)param_1;
  *(u32 *)(iVar10 + 4) = *(u32 *)(param_2 + 4);
  *(u32 *)(iVar10 + 8) = *(u32 *)(param_2 + 8);
  *(u32 *)(iVar10 + 0xc) = *(u32 *)(param_2 + 0xc);
  uVar3 = *(u32 *)(param_2 + 0x14);
  *(u32 *)(iVar10 + 0x10) = *(u32 *)(param_2 + 0x10);
  *(u32 *)(iVar10 + 0x14) = uVar3;
  func_0031a850(iVar10 + 0x18,param_2 + 0x18);
  uVar1 = *(u8 *)(param_2 + 0x195);
  uVar3 = *(u32 *)(param_2 + 0x174);
  uVar4 = *(u32 *)(param_2 + 0x178);
  uVar5 = *(u32 *)(param_2 + 0x17c);
  uVar11 = *(u32 *)(param_2 + 0x180);
  uVar6 = *(u32 *)(param_2 + 0x184);
  uVar7 = *(u32 *)(param_2 + 0x188);
  uVar8 = *(u32 *)(param_2 + 0x18c);
  uVar9 = *(u32 *)(param_2 + 400);
  uVar2 = *(u8 *)(param_2 + 0x194);
  *(u32 *)(iVar10 + 0x170) = *(u32 *)(param_2 + 0x170);
  *(u32 *)(iVar10 + 0x174) = uVar3;
  *(u32 *)(iVar10 + 0x178) = uVar4;
  *(u32 *)(iVar10 + 0x17c) = uVar5;
  *(u32 *)(iVar10 + 0x180) = uVar11;
  *(u32 *)(iVar10 + 0x184) = uVar6;
  *(u32 *)(iVar10 + 0x188) = uVar7;
  *(u32 *)(iVar10 + 0x18c) = uVar8;
  *(u32 *)(iVar10 + 400) = uVar9;
  *(u8 *)(iVar10 + 0x194) = uVar2;
  *(u8 *)(iVar10 + 0x195) = uVar1;
  return param_1;
}

void func_0031ae58(u32 *param_1,u64 param_2)

{
  int iVar1;
  s64 lVar2;
  u32 *puVar3;
  int iVar4;
  
  *param_1 = (int)param_2;
  iVar4 = 0;
  lVar2 = func_00168aa0(param_2,0x19);
  param_1[1] = (int)lVar2;
  puVar3 = param_1;
  if (0 < lVar2) {
    do {
      iVar1 = func_00168b38(*param_1,0x19,iVar4);
      puVar3[3] = *(u32 *)(iVar1 + 8);
      lVar2 = func_00168b38(*param_1,0x18,0);
      if (lVar2 == 0) {
        puVar3[2] = 0;
      }
      else {
        iVar1 = func_00168b38(*param_1,0x18,iVar4);
        puVar3[2] = *(u32 *)(iVar1 + 8);
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar4 < (int)param_1[1]);
  }
  return;
}
