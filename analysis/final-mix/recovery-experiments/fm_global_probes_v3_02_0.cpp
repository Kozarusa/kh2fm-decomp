#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern s32 D_0034f240;
extern s32 D_00352ae0;
extern s32 D_00352bd0;
extern f32 D_00359110;
extern f32 D_00359114;
extern f32 D_00359118;
extern f32 D_0035911c;
extern f32 D_00359120;
extern f32 D_00359124;
extern f32 D_00359128;
extern f32 D_0035912c;
extern f32 D_00359130;
extern f32 D_00359134;
extern f32 D_00359138;
extern f32 D_0035913c;
extern f32 D_00359140;
extern f32 D_00359144;
extern f32 D_00359148;
extern f32 D_0035914c;
extern u8 D_00359150;
extern u8 D_00359151;
extern u8 D_00359152;
extern s32 D_00359780;
extern s32 D_00359788;
extern s32 D_00359808;
extern s32 D_00359810;
extern s32 D_0035dad4;
extern s32 D_0035dad8;
extern s32 D_0035db00;
extern s32 D_0035db04;
extern s32 D_0035db08;
extern s32 D_0035db10;
extern f32 D_0035db20;
extern f32 D_0035db24;
extern f32 D_0035db28;
extern f32 D_0035db30;
extern f32 D_0035db34;
extern f32 D_0035db38;
extern s32 D_0035dce4;
extern s32 D_0035dce8;
extern s32 D_0035dcf0;
extern s32 D_0035dcf4;
extern s32 D_0035dcf8;
extern s32 D_0035dcfc;
extern u8 D_0035de14;
extern u8 D_0035de15;
extern s32 D_0035de20;
extern u8 D_0035de27;
extern s32 D_0035de30;
extern s32 D_0035de34;
extern s32 D_0035de38;
extern s32 D_0035de3c;
extern u8 D_0035de54;
extern s32 D_0035de5c;
extern u8 D_0035e440;
extern s32 D_0035ea40;
extern s32 D_0035eb48;
extern s32 D_0035eb4c;
extern u8 D_0035eb84;
extern s32 D_0035eb88;
extern s32 D_0035eb8c;
extern s32 D_0035ec94;
extern f32 D_0036e928;
extern f32 D_0036e92c;
extern f32 D_003707b0;
extern f32 D_003707b4;
extern f32 D_003707b8;
extern f32 D_003707bc;
extern f32 D_003714bc;
extern f32 D_003714c0;
extern f32 D_003714c4;
extern f32 D_003714c8;
extern s32 D_01d49350;
extern u32* D_01d49354;
extern s32 D_01d9e348;
extern s32 D_01d9e34c;
extern s32 D_01dad910;
extern s32 D_01dad914;
extern s32 D_01dad9c0;

void func_001c0150(u32 *param_1,u32 param_2)

{
  int iVar1;
  u32 *puVar2;
  
  *param_1 = param_2;
  iVar1 = 7;
  puVar2 = param_1;
  do {
    puVar2 = puVar2 + 1;
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  param_1[9] = 0;
  puVar2 = param_1 + 0xc;
  param_1[10] = 0;
  iVar1 = 3;
  param_1[0xb] = 0;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 2;
  } while (iVar1 != -1);
  if (D_01d49354 != (u32 *)0x0) {
    *(u32 **)((int)D_01d49354 + 0x50) = param_1;
    param_1[0x14] = 0;
    D_01d49354 = param_1;
    return;
  }
  D_01d49350 = param_1;
  D_01d49354 = param_1;
  param_1[0x14] = 0;
  return;
}

u32 func_001dc738(int param_1)

{
  if ((*(u32 *)(param_1 + 8) & 0x400000) == 0) {
    if (((D_0034f240 & 0x20) != 0) && (*(int *)(param_1 + 4) != 3)) {
      return 1;
    }
    if (((int)*(u32 *)(param_1 + 8) >> 0x1a & 1U) == 0) {
      return 0;
    }
  }
  return 1;
}

void func_001ddc08(void)

{
  int iVar1;
  u32 uVar2;
  
  if (D_00352ae0 != 0) {
    uVar2 = *(u32 *)(D_00352ae0 + 8);
    iVar1 = D_00352ae0;
    while( true ) {
      *(u32 *)(iVar1 + 8) = uVar2 | 0x4000000;
      iVar1 = *(int *)(iVar1 + 0x28);
      if (iVar1 == 0) break;
      uVar2 = *(u32 *)(iVar1 + 8);
    }
  }
  return;
}

void func_001ddc48(void)

{
  int iVar1;
  u32 uVar2;
  
  if (D_00352ae0 != 0) {
    uVar2 = *(u32 *)(D_00352ae0 + 8);
    iVar1 = D_00352ae0;
    while( true ) {
      *(u32 *)(iVar1 + 8) = uVar2 & 0xfbffffff;
      iVar1 = *(int *)(iVar1 + 0x28);
      if (iVar1 == 0) break;
      uVar2 = *(u32 *)(iVar1 + 8);
    }
  }
  return;
}

void func_001e0348(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01d9e348 = 0;
    D_01d9e34c = 0;
  }
  return;
}

void func_001e0d08(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x30) =
       *param_2;
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x34) = uVar1;
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x38) = uVar2;
  return;
}

void func_001e0d68(int param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x20) =
       *param_2;
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x24) = uVar1;
  *(u32 *)(*(int *)(D_00352bd0 + 0xdc4) + *(int *)(param_1 + 0x20) * 0x40 + 0x28) = uVar2;
  return;
}

void func_001e1df8(int param_1)

{
  u32 uVar1;
  
  if (D_0036e928 <= *(float *)(param_1 + 0xde4)) {
    *(u32 *)(param_1 + 0xde8) = 0;
    *(u32 *)(param_1 + 0xdfc) = 0;
    uVar1 = D_0036e92c;
    *(u32 *)(param_1 + 0xde4) = 0;
    *(u32 *)(param_1 + 0xdf8) = uVar1;
    *(u32 *)(param_1 + 0xdc0) = 4;
    *(u32 *)(param_1 + 0xdf4) = uVar1;
  }
  return;
}

void func_0020e960(void)

{
  D_00359150 = 0x80;
  D_00359110 = 0;
  D_0035914c = 0;
  D_0035912c = D_003707b0;
  D_00359148 = D_003707b4;
  D_00359130 = D_003707b8;
  D_00359151 = 0x80;
  D_00359114 = 0;
  D_00359134 = D_003707bc;
  D_00359118 = D_003707b0;
  D_0035911c = 0;
  D_00359124 = 0;
  D_00359120 = 0;
  D_00359128 = D_003707b0;
  D_00359138 = D_003707b4;
  D_0035913c = 0;
  D_00359140 = 0;
  D_00359144 = D_003707b4;
  D_00359152 = 0x80;
  return;
}

void func_0020ea48(u8 param_1,u8 param_2,u8 param_3)

{
  D_00359150 = param_1;
  D_00359152 = param_3;
  D_00359151 = param_2;
  return;
}

void func_0020ea70(u8 param_1,u8 param_2)

{
  D_00359118 = (float)param_2;
  D_0035911c = (float)param_1;
  return;
}

void func_0020eac0(void)

{
  D_00359810 = 0x70004000;
  D_00359788 = 0x70000000;
  D_00359808 = 0;
  D_00359780 = 0;
  return;
}

void func_002247e8(void)

{
  if ((D_0035dad8 != D_0035de20) && (D_0035dad4 < 5)) {
    D_0035dad8 = D_0035de20;
    D_0035dad4 = D_0035dad4 + 1;
  }
  return;
}

void func_00225298(void)

{
  D_01dad910 = 0xffffffff;
  D_01dad914 = 0xffffffff;
  return;
}

char func_00225b00(int param_1)

{
  char cVar1;
  
  if (param_1 == -1) {
    return D_0035de54;
  }
  cVar1 = '\0';
  if ((D_0035de54 != '\0') || ((param_1 < D_0035de20 && (D_0035de20 == D_0035de5c)))) {
    cVar1 = '\x01';
  }
  return cVar1;
}

void func_00226a78(void)

{
  D_0035db10 = 0;
  D_0035de27 = 0;
  D_0035de30 = 0;
  D_0035de34 = 0;
  D_0035de38 = 0;
  D_0035de3c = 0;
  return;
}

int func_00227a28(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(D_0035dcf0 + 4);
  iVar1 = D_0035dcf0;
  while( true ) {
    if (iVar3 == 0) {
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    if (0x7f < iVar2) break;
    iVar3 = *(int *)(iVar1 + 0x58);
    iVar1 = iVar1 + 0x54;
  }
  return 0;
}

void func_00227da8(u64 *param_1)

{
  u64 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  u64 *puVar5;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    piVar4 = (int *)(iVar3 + D_0035dcfc);
    iVar3 = iVar3 + 0x28;
    if (*piVar4 == -1) {
      puVar5 = param_1 + 4;
      do {
        uVar1 = param_1[1];
        *(u64 *)piVar4 = *param_1;
        *(u64 *)(piVar4 + 2) = uVar1;
        param_1 = param_1 + 2;
        piVar4 = piVar4 + 4;
      } while (param_1 != puVar5);
      *(u64 *)piVar4 = *param_1;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x60);
  return;
}

void func_00228420(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_0035db00 = 0;
    D_0035db08 = 0;
    D_0035db04 = 0;
  }
  return;
}

void func_0022d7e8(void)

{
  int iVar1;
  u32 *puVar2;
  
  puVar2 = &D_01dad9c0;
  iVar1 = 0x1f;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    *(u16 *)(puVar2 + 1) = 0xffff;
    *(u16 *)((int)puVar2 + 6) = 0xffff;
    puVar2 = puVar2 + 2;
  } while (-1 < iVar1);
  return;
}

int func_0022e330(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(D_0035dcf4 + 4);
  iVar1 = D_0035dcf4;
  while( true ) {
    if (iVar3 == param_1) {
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    if (0x5f < iVar2) break;
    iVar3 = *(int *)(iVar1 + 0x38);
    iVar1 = iVar1 + 0x34;
  }
  return 0;
}

void func_0022e368(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar2 + 1;
    if (*(int *)(iVar1 + D_0035dcf4 + 4) == -1) {
      *(int *)(iVar1 + D_0035dcf4 + 4) = (int)*(short *)(param_1 + 8);
      *(int *)(iVar1 + D_0035dcf4) = (int)*(short *)(param_1 + 10);
      *(u16 *)(iVar1 + D_0035dcf4 + 8) = *(u16 *)(param_1 + 0xc);
      *(u16 *)(iVar1 + D_0035dcf4 + 0x2e) = *(u16 *)(param_1 + 4);
      *(u32 *)(iVar1 + D_0035dcf4 + 0xc) = 0;
      return;
    }
    iVar1 = iVar1 + 0x34;
  } while (iVar2 < 0x60);
  return;
}

void func_00230838(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = iVar1 * 8;
    iVar1 = iVar1 + 1;
    piVar2 = (int *)(iVar3 + D_0035dce8);
    if (*piVar2 == 0) {
      *piVar2 = param_1;
      return;
    }
  } while (iVar1 < 0x40);
  return;
}

void func_00230878(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  while( true ) {
    iVar3 = iVar1 * 8;
    iVar1 = iVar1 + 1;
    piVar2 = (int *)(iVar3 + D_0035dce8);
    iVar3 = *piVar2;
    if ((iVar3 != 0) && (*(short *)(iVar3 + 4) == *(short *)(param_1 + 4))) break;
    if (0x3f < iVar1) {
      return;
    }
  }
  piVar2[1] = param_1;
  return;
}

void func_00230d78(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 8;
    iVar2 = iVar2 + 1;
    if (*(int *)(iVar1 + D_0035dce4) == -1) {
      *(int *)(iVar1 + D_0035dce4) = (int)*(short *)(param_1 + 4);
      *(u16 *)(iVar1 + D_0035dce4 + 4) = *(u16 *)(param_1 + 6);
      *(u16 *)(iVar1 + D_0035dce4 + 6) = *(u16 *)(param_1 + 8);
      return;
    }
  } while (iVar2 < 0x80);
  return;
}

void func_002314c0(u32 *param_1)

{
  D_0035db20 = *param_1;
  D_0035db24 = param_1[1];
  D_0035db28 = param_1[2];
  D_0035db30 = param_1[3];
  D_0035db34 = param_1[4];
  D_0035db38 = param_1[5];
  return;
}

void func_00232110(int param_1)

{
  D_0035de14 = 1;
  if (*(short *)(param_1 + 6) == 0) {
    D_0035de15 = 0;
    return;
  }
  if (*(short *)(param_1 + 6) == 1) {
    D_0035de15 = 1;
    return;
  }
  return;
}

void func_00232db0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    piVar3 = (int *)(iVar2 + D_0035dcf8);
    if ((*piVar3 != -1) && (piVar3[1] == param_1)) break;
    if (0x3f < iVar1) {
      return;
    }
  }
  *piVar3 = -1;
  *(u32 *)(iVar2 + D_0035dcf8 + 4) = 0xffffffff;
  *(u32 *)(iVar2 + D_0035dcf8 + 8) = 0;
  return;
}

void func_00236d10(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u8 *puVar4;
  
  iVar1 = 0x3500;
  puVar4 = &D_0035e440;
  iVar2 = 0x3600;
  iVar3 = 0x3f;
  do {
    *(int *)(puVar4 + 0x10) = iVar2;
    iVar3 = iVar3 + -1;
    *(int *)(puVar4 + 0x14) = iVar1;
    *puVar4 = 0;
    iVar2 = iVar2 + 0x20;
    *(u32 *)(puVar4 + 4) = 0;
    iVar1 = iVar1 + 4;
    *(u32 *)(puVar4 + 8) = 0;
    puVar4 = puVar4 + 0x18;
  } while (-1 < iVar3);
  D_0035ea40 = 1;
  return;
}

void func_00236d60(void)

{
  u8 *puVar1;
  
  puVar1 = &D_0035e440;
  D_0035e440 = 0;
  while( true ) {
    *(u32 *)(puVar1 + 4) = 0;
    puVar1 = puVar1 + 0x18;
    if (0x35ea3f < (int)puVar1) break;
    *puVar1 = 0;
  }
  return;
}

void func_00239e60(float param_1,float param_2,float param_3,int param_4)

{
  u32 uVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  
  *(float *)(param_4 + 0x134) = param_1;
  *(float *)(param_4 + 0x138) = param_2;
  fVar3 = D_003714bc;
  iVar4 = 0;
  bVar2 = param_1 == D_003714bc;
  *(float *)(param_4 + 0x13c) = param_3;
  if (((bVar2) && (param_2 == fVar3)) && (param_3 == fVar3)) {
    uVar1 = *(u32 *)(param_4 + 0xb8);
  }
  else {
    iVar4 = 1;
    uVar1 = *(u32 *)(param_4 + 0xb8);
  }
  *(u32 *)(param_4 + 0xb8) = uVar1 & 0xfffffffd | iVar4 << 1;
  return;
}

void func_00239eb8(float param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  
  *(float *)(param_2 + 0x134) = param_1;
  iVar2 = 0;
  if (((param_1 == D_003714c0) && (*(float *)(param_2 + 0x138) == D_003714c0)) &&
     (*(float *)(param_2 + 0x13c) == D_003714c0)) {
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  else {
    iVar2 = 1;
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  *(u32 *)(param_2 + 0xb8) = uVar1 & 0xfffffffd | iVar2 << 1;
  return;
}

void func_00239f18(float param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  
  *(float *)(param_2 + 0x138) = param_1;
  iVar2 = 0;
  if (((*(float *)(param_2 + 0x134) == D_003714c4) && (param_1 == D_003714c4)) &&
     (*(float *)(param_2 + 0x13c) == D_003714c4)) {
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  else {
    iVar2 = 1;
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  *(u32 *)(param_2 + 0xb8) = uVar1 & 0xfffffffd | iVar2 << 1;
  return;
}

void func_00239f78(float param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  
  *(float *)(param_2 + 0x13c) = param_1;
  iVar2 = 0;
  if (((*(float *)(param_2 + 0x134) == D_003714c8) &&
      (*(float *)(param_2 + 0x138) == D_003714c8)) && (param_1 == D_003714c8)) {
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  else {
    iVar2 = 1;
    uVar1 = *(u32 *)(param_2 + 0xb8);
  }
  *(u32 *)(param_2 + 0xb8) = uVar1 & 0xfffffffd | iVar2 << 1;
  return;
}

bool func_0023d2e0(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = D_0035eb48 == -1;
  iVar2 = D_0035eb48;
  if (bVar1) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  return !bVar1;
}

bool func_0023d300(int *param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = D_0035eb4c == -1;
  iVar2 = D_0035eb4c;
  if (bVar1) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  return !bVar1;
}

void func_0023edb0(int param_1)

{
  if (D_0035eb88 == param_1) {
    D_0035eb84 = D_0035eb84 + '\x01';
    return;
  }
  if (D_0035eb88 != 0) {
    D_0035eb8c = D_0035eb88;
  }
  D_0035eb88 = param_1;
  return;
}

void func_00240fd8(s64 param_1,u32 param_2)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = (s64)*(char *)(D_0035ec94 + 1);
  }
  iVar1 = (int)param_1 * 0x20 + D_0035ec94;
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | param_2;
  return;
}

s64 func_002413f0(void)

{
  bool bVar1;
  s64 lVar2;
  s64 lVar3;
  int iVar4;
  
  lVar3 = (s64)*(char *)(D_0035ec94 + 1);
  bVar1 = lVar3 < 99;
  if (bVar1) {
    iVar4 = *(char *)(D_0035ec94 + 1) * 0x20 + D_0035ec94;
    do {
      if ((((*(u8 *)(iVar4 + 8) ^ 1) & 1) == 0) && ((*(u32 *)(iVar4 + 8) & 2) == 0)) break;
      lVar3 = (s64)((int)lVar3 + 1);
      bVar1 = lVar3 < 99;
      iVar4 = iVar4 + 0x20;
    } while (bVar1);
  }
  lVar2 = -1;
  if (bVar1) {
    lVar2 = lVar3;
  }
  return lVar2;
}

u32 func_00241770(s64 param_1)

{
  if (param_1 < 0) {
    param_1 = (s64)*(char *)(D_0035ec94 + 1);
  }
  return *(int *)((int)param_1 * 0x20 + D_0035ec94 + 8) >> 4 & 1;
}
