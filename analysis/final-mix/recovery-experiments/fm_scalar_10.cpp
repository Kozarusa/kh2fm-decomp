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

u64 func_00310560(u64 param_1)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310518(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

s64 func_003105b0(u32 param_1)

{
  s64 lVar1;
  s64 lVar2;
  int iVar3;
  
  iVar3 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar3 + 8))) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(s64 *)(iVar3 + 0x18);
    if ((*(u32 *)(iVar3 + 0xc) & 1) != 0) {
      lVar1 = func_0030ff08();
      lVar2 = lVar2 + (lVar1 - *(s64 *)(iVar3 + 0x10));
    }
  }
  return lVar2;
}

u64 func_00310768(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  s64 lVar1;
  u64 uVar2;
  
  lVar1 = func_0030edb0();
  uVar2 = func_00310670(param_1,param_2,param_3,param_4);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return uVar2;
}

float func_00310900(u64 param_1)

{
  float fVar1;
  
  if ((s64)param_1 < 0) {
    fVar1 = (float)func_00311af0(param_1 & 1 | param_1 >> 1);
    fVar1 = fVar1 + fVar1;
  }
  else {
    fVar1 = (float)func_00311af0();
  }
  return 1.47456e+08 / fVar1;
}

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

void func_00313ed8(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u8 auStack_80 [32];
  u8 auStack_60 [4];
  u32 uStack_5c;
  u8 auStack_40 [32];
  u64 uStack_20;
  u64 uStack_18;
  
  uStack_20 = param_1;
  uStack_18 = param_2;
  func_003147a0(&uStack_20,auStack_80);
  func_003147a0(&uStack_18,auStack_60);
  uStack_5c = uStack_5c ^ 1;
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

void func_00314480(u32 param_1,u32 param_2,u32 param_3,u64 param_4)

{
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u64 uStack_20;
  
  uStack_30 = param_1;
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_20 = param_4;
  func_003146c8(&uStack_30);
  return;
}

void func_003144b0(u64 param_1)

{
  u64 uVar1;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u64 uStack_30;
  u64 auStack_20 [2];
  
  auStack_20[0] = param_1;
  func_003147a0(auStack_20,&uStack_40);
  uVar1 = (s64)(uStack_30 << 2) >> 0x20;
  if ((uStack_30 & 0x3fffffff) != 0) {
    uVar1 = uVar1 | 1;
  }
  func_00314698(uStack_40,uStack_3c,uStack_38,uVar1);
  return;
}

void func_00314640(u32 *param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = *param_1;
  param_2[1] = uVar1 >> 0x1f;
  uVar2 = uVar1 >> 0x17 & 0xff;
  if (uVar2 == 0) {
    *param_2 = 2;
    return;
  }
  param_2[2] = uVar2 - 0x7f;
  *param_2 = 3;
  param_2[3] = (uVar1 & 0x7fffff) << 7 | 0x40000000;
  return;
}

void func_00314b00(u8 *param_1,u64 *param_2)

{
  u8 bVar1;
  u64 uVar2;
  u32 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (s64)(int)((bVar1 & 0x7f) << (uVar3 & 0x1f)) | uVar2;
    uVar3 = uVar3 + 7;
  } while ((bVar1 & 0x80) != 0);
  *param_2 = uVar2;
  return;
}

void func_00314b38(u8 *param_1,u64 *param_2)

{
  u8 bVar1;
  u64 uVar2;
  u64 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (s64)(int)((bVar1 & 0x7f) << ((u32)uVar3 & 0x1f)) | uVar2;
    uVar3 = (u64)(int)((u32)uVar3 + 7);
  } while ((bVar1 & 0x80) != 0);
  if ((uVar3 < 0x40) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1L << uVar3;
  }
  *param_2 = uVar2;
  return;
}

u32 func_00314dd8(int param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 auStack_30 [4];
  
  uVar1 = func_003149e8(*(u8 *)(param_1 + 0x14));
  iVar2 = func_00311aa0(param_2,uVar1);
  func_00314b90(*(u8 *)(param_1 + 0x14),*(u32 *)(param_1 + 8),
               *(int *)(param_1 + 0xc) - iVar2,auStack_30);
  return auStack_30[0];
}

u32 func_003160e0(int param_1,int param_2,u32 param_3,u32 *param_4)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) {
    *param_4 = param_3;
    param_4[1] = 6;
    param_4[3] = 8;
    return 1;
  }
  return 0;
}

void func_00316d18(u32 param_1,u64 param_2)

{
  u32 *puStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  
  uStack_20 = param_1;
  uStack_28 = func_002ff3fc();
  puStack_30 = &uStack_20;
  uStack_2c = 1;
  uStack_1c = uStack_28;
  func_003032d0(param_2,&puStack_30);
  return;
}

void func_00316f70(u8 *param_1,u64 *param_2)

{
  u8 bVar1;
  u64 uVar2;
  u64 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (s64)(int)((bVar1 & 0x7f) << ((u32)uVar3 & 0x1f)) | uVar2;
    uVar3 = (u64)(int)((u32)uVar3 + 7);
  } while ((bVar1 & 0x80) != 0);
  if ((uVar3 < 0x40) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1L << uVar3;
  }
  *param_2 = uVar2;
  return;
}

void func_00319788(void)

{
  func_00100350();
  func_00101ce0();
  return;
}

void func_0031bae0(u32 *param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  uVar4 = param_2[4];
  uVar5 = param_2[5];
  uVar6 = param_2[6];
  uVar7 = param_2[7];
  uVar8 = param_2[8];
  uVar9 = param_2[9];
  uVar10 = param_2[10];
  uVar11 = param_2[0xb];
  uVar12 = param_2[0xc];
  uVar13 = param_2[0xd];
  uVar14 = param_2[0xe];
  uVar15 = param_2[0xf];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  param_1[4] = uVar4;
  param_1[5] = uVar5;
  param_1[6] = uVar6;
  param_1[7] = uVar7;
  param_1[8] = uVar8;
  param_1[9] = uVar9;
  param_1[10] = uVar10;
  param_1[0xb] = uVar11;
  param_1[0xc] = uVar12;
  param_1[0xd] = uVar13;
  param_1[0xe] = uVar14;
  param_1[0xf] = uVar15;
  return;
}

void func_0031c068(u64 param_1)

{
  func_00138988();
  func_0014b9a8((int)param_1 + 0x1c0);
  func_00138de0(param_1);
  func_0014b9a8((int)param_1 + 0x1e0);
  return;
}

void func_0031e208(u64 param_1,int param_2,u32 *param_3,u16 param_4,
                 u32 *param_5)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  if ((*(u64 *)(param_2 + 0x70) & 0x78) == 0) {
    uVar4 = *param_3;
    if ((uVar4 & 0x800) != 0) {
      *(u16 *)(param_2 + 0x62) = param_4;
      if ((u32 *)(param_2 + 0x40) != param_5) {
        uVar1 = param_5[1];
        uVar2 = param_5[2];
        uVar3 = param_5[3];
        *(u32 *)(param_2 + 0x40) = *param_5;
        *(u32 *)(param_2 + 0x44) = uVar1;
        *(u32 *)(param_2 + 0x48) = uVar2;
        *(u32 *)(param_2 + 0x4c) = uVar3;
      }
      uVar4 = *param_3;
    }
    if ((uVar4 & 0x1000) != 0) {
      *(u16 *)(param_2 + 100) = param_4;
      if ((u32 *)(param_2 + 0x50) != param_5) {
        uVar1 = param_5[1];
        uVar2 = param_5[2];
        uVar3 = param_5[3];
        *(u32 *)(param_2 + 0x50) = *param_5;
        *(u32 *)(param_2 + 0x54) = uVar1;
        *(u32 *)(param_2 + 0x58) = uVar2;
        *(u32 *)(param_2 + 0x5c) = uVar3;
      }
    }
  }
  return;
}

u8 * func_00321728(u8 *param_1,u64 param_2,u64 param_3)

{
  u8 *pbVar1;
  int iVar2;
  
  pbVar1 = (u8 *)0x0;
  iVar2 = 0;
  do {
    if ((*param_1 == param_2) && (*(u16 *)(param_1 + 2) == param_3)) {
      return param_1;
    }
    if ((pbVar1 == (u8 *)0x0) || (param_1[1] < pbVar1[1])) {
      pbVar1 = param_1;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
  } while (iVar2 < 0x80);
  *pbVar1 = (u8)param_2;
  *(short *)(pbVar1 + 2) = (short)param_3;
  pbVar1[1] = 0;
  return pbVar1;
}

u32 func_00321cb0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *param_1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x14);
    }
    if (iVar1 == 0) break;
    if (iVar1 == param_2) {
      return 1;
    }
  }
  return 0;
}

void func_00322ba8(int param_1)

{
  func_00108698(param_1 + 0x38);
  func_001ddd10(param_1 + 0xc0);
  return;
}

void func_00323af8(u64 *param_1,u64 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u64 *puVar5;
  u64 *puVar6;
  u64 uVar7;
  u64 uVar8;
  u64 uVar9;
  
  puVar5 = param_1 + 4;
  uVar7 = param_2[1];
  iVar4 = 1;
  uVar8 = param_2[2];
  puVar6 = param_2 + 4;
  uVar9 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar7;
  param_1[2] = uVar8;
  param_1[3] = uVar9;
  do {
    uVar1 = *(u32 *)((int)puVar6 + 4);
    uVar2 = *(u32 *)(puVar6 + 1);
    uVar3 = *(u32 *)((int)puVar6 + 0xc);
    *(u32 *)puVar5 = *(u32 *)puVar6;
    *(u32 *)((int)puVar5 + 4) = uVar1;
    *(u32 *)(puVar5 + 1) = uVar2;
    *(u32 *)((int)puVar5 + 0xc) = uVar3;
    puVar5 = puVar5 + 2;
    iVar4 = iVar4 + -1;
    puVar6 = puVar6 + 2;
  } while (iVar4 != -1);
  *(u32 *)(param_1 + 8) = *(u32 *)(param_2 + 8);
  return;
}

u32 func_00324718(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *param_1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1c);
    }
    if (iVar1 == 0) break;
    if (iVar1 == param_2) {
      return 1;
    }
  }
  return 0;
}
