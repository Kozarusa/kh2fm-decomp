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
extern s32 D_01e2be1c;

int func_0022f4f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = *D_0035dcfc;
  piVar3 = D_0035dcfc;
  while( true ) {
    iVar1 = (int)piVar3 + 0x17;
    piVar3 = piVar3 + 10;
    if (iVar4 == param_1) {
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    if (0x5f < iVar2) break;
    iVar4 = *piVar3;
  }
  return 0;
}

u32 func_00241770(s64 param_1)

{
  if (param_1 < 0) {
    param_1 = (s64)*(char *)(D_0035ec94 + 1);
  }
  return *(int *)((int)param_1 * 0x20 + D_0035ec94 + 8) >> 4 & 1;
}

u32 func_00241a00(void)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  
  iVar1 = 0;
  puVar2 = (u32 *)(D_0035ec94 + 8);
  uVar3 = *puVar2;
  while( true ) {
    puVar2 = puVar2 + 8;
    if ((uVar3 & 0x10) != 0) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    if (0x62 < iVar1) break;
    uVar3 = *puVar2;
  }
  return 0;
}

u32 func_00242418(u8 *param_1,int param_2)

{
  u8 bVar1;
  
  while (param_2 = param_2 + -1, -1 < param_2) {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    D_0035ecc4 = D_0035ecc4 << 8 ^
                   *(u32 *)((D_0035ecc4 >> 0x18 ^ (u32)bVar1) * 4 + D_0035ecc0);
  }
  return ~D_0035ecc4;
}

void func_00243190(int param_1)

{
  u32 uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = 0;
  piVar2 = &D_003718d0;
  iVar3 = D_003718d0;
  while ((piVar2 = piVar2 + 1, iVar3 != param_1 && (uVar1 = uVar1 + 1, uVar1 < 0xb))) {
    iVar3 = *piVar2;
  }
  return;
}

short * func_00253330(short param_1)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  psVar1 = (short *)0x0;
  iVar2 = 0;
  if (-1 < D_003726d0) {
    iVar4 = 0;
    do {
      psVar3 = (short *)((int)&D_003726d0 + iVar4);
      iVar2 = iVar2 + 1;
      iVar4 = iVar2 * 0x10;
      if (*psVar3 == param_1) {
        psVar1 = psVar3;
      }
    } while (-1 < (&D_003726d0)[iVar2 * 8]);
  }
  return psVar1;
}

void func_00253888(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &D_0035eee0;
  D_0035ef50 = 0;
  iVar2 = 6;
  do {
    iVar2 = iVar2 + -1;
    if (piVar3[3] != 0) {
      iVar1 = *piVar3;
      if (param_1 <= iVar1) {
        *piVar3 = 0;
        piVar3[1] = 0;
        if (iVar1 == param_1) {
          D_0035ef50 = piVar3[3] + -0x1dae6c0;
        }
        piVar3[3] = 0;
        piVar3[2] = 0;
      }
    }
    piVar3 = piVar3 + 4;
  } while (-1 < iVar2);
  D_0035ef54 = param_1;
  return;
}

u32 func_00257fa8(int param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  uVar3 = (u32)D_0035ef70;
  while( true ) {
    if ((uVar3 & 1) != 0) {
      if (iVar1 == param_1) {
        return uVar2;
      }
      iVar1 = iVar1 + 1;
    }
    uVar2 = uVar2 + 1;
    if (7 < (int)uVar2) break;
    uVar3 = (int)(u32)D_0035ef70 >> (uVar2 & 0x1f);
  }
  return 0xffffffff;
}

int func_00257ff8(u32 param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  uVar3 = (u32)D_0035ef70;
  while( true ) {
    if ((uVar3 & 1) != 0) {
      if (uVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    }
    uVar2 = uVar2 + 1;
    if (7 < (int)uVar2) break;
    uVar3 = (int)(u32)D_0035ef70 >> (uVar2 & 0x1f);
  }
  return -1;
}

void func_00258ce8(u16 *param_1)

{
  int iVar1;
  u16 *puVar2;
  
  if (param_1 == (u16 *)0x0) {
    D_0035f0a8 = 0x9fcf;
    D_0035f0ac = 0x9fd1;
    D_0035f0aa = 0x9fd0;
    return;
  }
  iVar1 = 2;
  puVar2 = &D_0035f0a8;
  do {
    iVar1 = iVar1 + -1;
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  return;
}

void func_00258dc8(void)

{
  D_0035f090 = 0xffff;
  D_0035f096 = 0xffff;
  D_0035f092 = 0xffff;
  D_0035f094 = 0xffff;
  return;
}

u32 func_002671e8(int param_1)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  uVar1 = *(char *)(D_0035f0e4 + 0x20) * 10;
  uVar3 = uVar1;
  do {
    iVar4 = iVar4 + 1;
    if ((*(u32 *)(D_0035f0e4 + 0x18) & 1 << (uVar3 & 0x1f)) != 0) {
      if (iVar2 == param_1) {
        return uVar3;
      }
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar1 + iVar4;
  } while (iVar4 < 10);
  return 0xffffffff;
}

void func_0026dd18(u32 param_1,u32 param_2,s64 param_3)

{
  D_0035f118 = param_1;
  D_0035f11c = param_2;
  if (-1 < param_3) {
    D_0035f120 = (char)param_3;
  }
  return;
}

void func_002799b0(void)

{
  s64 lVar1;
  int iVar2;
  
  *(u16 *)(D_0035f230 + 4) = 0;
  lVar1 = 0;
  if ('\0' < *(char *)(D_0035f230 + 7)) {
    do {
      iVar2 = (int)lVar1 * 8 + D_0035f230;
      lVar1 = (s64)((int)lVar1 + 1);
      if (*(char *)(iVar2 + 0xe) != '\0') {
        *(short *)(D_0035f230 + 4) = *(short *)(D_0035f230 + 4) + (short)*(char *)(iVar2 + 0x11)
        ;
      }
    } while (lVar1 < *(char *)(D_0035f230 + 7));
  }
  return;
}

bool func_0027bf20(int param_1)

{
  bool bVar1;
  int iVar2;
  s64 lVar3;
  
  bVar1 = true;
  iVar2 = param_1 * 8 + D_0035f230;
  lVar3 = (s64)((int)*(short *)(D_0035f230 + 2) - (int)*(short *)(D_0035f230 + 4));
  if (lVar3 < 0) {
    lVar3 = 0;
  }
  if (*(char *)(iVar2 + 0xe) == '\0') {
    bVar1 = *(char *)(iVar2 + 0x11) <= lVar3;
  }
  return bVar1;
}

short func_00282c68(short param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  sVar1 = -1;
  iVar2 = 0;
  if (-1 < D_003741f0) {
    psVar3 = &D_003741f0;
    do {
      if (*psVar3 == param_1) {
        sVar1 = psVar3[1];
      }
      iVar2 = iVar2 + 1;
      psVar3 = &D_003741f0 + iVar2 * 2;
    } while (-1 < (&D_003741f0)[iVar2 * 2]);
  }
  return sVar1;
}

u32 func_00285d18(char param_1)

{
  char cVar1;
  char *pcVar2;
  
  if (-1 < D_003743c0) {
    pcVar2 = &D_003743c0;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      if (cVar1 == param_1) {
        return 1;
      }
    } while (-1 < *pcVar2);
  }
  return 0;
}

void func_00287d68(void)

{
  D_0035f2fc = D_0035f2f8;
  D_0035f308 = D_0035f304;
  D_0035f310 = D_0035f30c;
  return;
}

void func_00288018(void)

{
  *D_0035f324 = 0;
  D_0035f324[1] = 0;
  D_0035f324[2] = 0;
  D_0035f324[3] = 0;
  return;
}

void func_0028d068(u32 param_1,s64 param_2)

{
  int iVar1;
  int iVar2;
  
  if (-1 < param_2) {
    *(u32 *)((int)param_2 * 4 + D_0035f40c) = param_1;
    return;
  }
  iVar1 = 0;
  if (0 < D_0035f404) {
    do {
      iVar2 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      *(u32 *)(iVar2 + D_0035f40c) = param_1;
    } while (iVar1 < D_0035f404);
  }
  return;
}

void func_0028d188(int param_1)

{
  u32 uVar1;
  
  *(u32 *)(param_1 + 0x1b8) = 0;
  *(u8 *)(param_1 + 0x19c) = 0;
  uVar1 = D_00374438;
  *(u8 *)(param_1 + 0x19d) = 0;
  *(u32 *)(param_1 + 0x1a0) = uVar1;
  *(u32 *)(param_1 + 0x1a4) = 0;
  *(u32 *)(param_1 + 0x1a8) = 0;
  *(u32 *)(param_1 + 0x1ac) = 0;
  *(u32 *)(param_1 + 0x1b0) = 0;
  *(u32 *)(param_1 + 0x1b4) = 0;
  return;
}

u32 func_00292a90(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = D_0035f4d4;
  if (0 < D_0035f4d0) {
    do {
      if (((piVar2[1] & 1U) != 0) && (*piVar2 == param_1)) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar1 < D_0035f4d0);
  }
  return 0;
}

void func_002a4990(int param_1)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  u8 *pbVar4;
  
  if (param_1 < 0) {
    iVar2 = *(int *)(D_0035f5e4 + 0x1088);
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    param_1 = *(int *)(D_0035f5e4 + 0x1084) + (iVar2 >> 3);
  }
  iVar3 = 0;
  iVar2 = 0;
  pbVar4 = (u8 *)(D_0035f5e4 + 0x1001);
  bVar1 = *pbVar4;
  while ((pbVar4 = pbVar4 + 8, bVar1 == 0 || (iVar3 = iVar3 + (u32)bVar1, iVar3 <= param_1))) {
    iVar2 = iVar2 + 1;
    if (0xe < iVar2) {
      return;
    }
    bVar1 = *pbVar4;
  }
  return;
}

u32 func_002ad338(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  while( true ) {
    uVar2 = uVar1 & 0x1f;
    uVar1 = uVar1 + 1;
    if ((*(u32 *)(uVar3 * 4 + D_0035f620 + 0x13c) & 1 << uVar2) == 0) {
      return 0;
    }
    if (0xc < (int)uVar1) break;
    uVar3 = uVar1 >> 5;
  }
  return 1;
}

bool func_002b16d8(void)

{
  return *(int *)(D_0035f634 + 0x55fc) == 0x7e && *(int *)(D_0035f634 + 0x5afc) == 0x81;
}

u32 func_002b99a0(void)

{
  return D_01e2a3c0;
}

void func_002bafb0(int param_1,s64 param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01e2a5e8 = 0;
    D_01e2a5ec = 0;
    D_01e2a5f0 = 0;
    D_01e2a5f4 = 0;
  }
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    iVar2 = 0;
    piVar1 = &D_01e2a9f8;
    do {
      *piVar1 = iVar2;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 0x20);
    D_01e2aa78 = 0x20;
  }
  return;
}

void func_002bb100(int param_1,int param_2,u8 param_3)

{
  *(int *)(param_1 + 0x14) = D_003616e8;
  D_003616e8 = D_003616e8 + 1;
  if (D_003616e8 == 0) {
    D_003616e8 = 1;
  }
  *(u8 *)(param_1 + 0x31) = param_3;
  *(u32 *)(param_1 + 0x24) = 0;
  *(u8 *)(param_1 + 0x30) = 1;
  if (param_2 == 1) {
    *(u32 *)(param_1 + 0x24) = 2;
  }
  *(u16 *)(param_1 + 0x28) = 0x3fff;
  *(u16 *)(param_1 + 0x2c) = 0x40;
  if (D_01e2aa84 != 0) {
    *(int *)(D_01e2aa84 + 0x1c) = param_1;
    *(u32 *)(param_1 + 0x1c) = 0;
    D_01e2aa84 = param_1;
    return;
  }
  D_01e2aa80 = param_1;
  D_01e2aa84 = param_1;
  *(u32 *)(param_1 + 0x1c) = 0;
  return;
}

int func_002bbda0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = D_01e2aa80;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x1c);
    }
    iVar2 = iVar1;
    if (iVar2 == 0) break;
    if (*(int *)(iVar2 + 0x14) == param_1) {
      return iVar2;
    }
  }
  return 0;
}

void func_002bbe38(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = D_01e2aa80;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x1c);
    }
    if (iVar2 == 0) break;
    iVar1 = iVar2;
    if (*(char *)(iVar2 + 0x31) == '\x02') {
      *(u32 *)(iVar2 + 0x24) = *(u32 *)(iVar2 + 0x24) | 4;
    }
  }
  return;
}

void func_002bbed0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = D_01e2aa80;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x1c);
    }
    if (iVar2 == 0) break;
    iVar1 = iVar2;
    if (*(char *)(iVar2 + 0x31) == '\x02') {
      *(u32 *)(iVar2 + 0x24) = *(u32 *)(iVar2 + 0x24) | 8;
    }
  }
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
  *(u32 *)(iVar1 + 0x22c) = D_00374fe0;
  return;
}

void func_002cb188(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01e2be10 = D_00375870;
    D_01e2be14 = D_00375874;
  }
  return;
}

void func_002cb5d8(u32 param_1,u8 *param_2)

{
  u32 uVar1;
  
  *(u32 *)(param_2 + 0x14) = param_1;
  *param_2 = 0;
  uVar1 = D_00375884;
  *(u32 *)(param_2 + 0x8c) = 0xffffffff;
  *(u32 *)(param_2 + 0x1c) = uVar1;
  *(u32 *)(param_2 + 4) = 0;
  uVar1 = D_00375888;
  *(u32 *)(param_2 + 8) = 0;
  *(u32 *)(param_2 + 0x20) = uVar1;
  *(u32 *)(param_2 + 0xc) = 0;
  uVar1 = D_0037588c;
  param_2[0x10] = 0;
  *(u32 *)(param_2 + 0x24) = uVar1;
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
  u32 uVar1;
  
  if (*(char *)(param_1 + 0x87) != '\0') {
    *(u32 *)(param_1 + 0x18) = 0;
    *(u32 *)(param_1 + 0x88) = 0;
    uVar1 = D_003758ec;
    *(u32 *)(param_1 + 4) = 0;
    *(u32 *)(param_1 + 0x1c) = uVar1;
    *(u32 *)(param_1 + 8) = 0;
  }
  return;
}

bool func_002cf1f8(int param_1,int param_2)

{
  if (((D_00361f60 != 0) && ((*(u32 *)(param_1 + 0x588) & 0x8000000) != 0)) &&
     ((*(u32 *)(param_2 + 0x588) & 0x8000000) != 0)) {
    return *(int *)(param_1 + 0xaf4) == *(int *)(param_2 + 0xaf4);
  }
  return true;
}

float func_002d0e10(float param_1)

{
  if (0.0 < param_1) {
    for (; D_0037599c < param_1; param_1 = param_1 - D_003759a0) {
    }
  }
  else {
    for (; param_1 < D_003759a4; param_1 = param_1 + D_003759a0) {
    }
  }
  return param_1;
}

float func_002d48b8(float param_1)

{
  if (0.0 < param_1) {
    for (; D_00375ae0 < param_1; param_1 = param_1 - D_00375ae4) {
    }
  }
  else {
    for (; param_1 < D_00375ae8; param_1 = param_1 + D_00375ae4) {
    }
  }
  return param_1;
}

void func_002d8d40(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = D_00375c8c;
  *param_2 = *(float *)(param_1 + 0x1d8) + D_00375c8c;
  *param_3 = *(float *)(param_1 + 0x1d4) - fVar1;
  return;
}

float func_002de968(float param_1)

{
  if (0.0 < param_1) {
    for (; D_00375e24 < param_1; param_1 = param_1 - D_00375e28) {
    }
  }
  else {
    for (; param_1 < D_00375e2c; param_1 = param_1 + D_00375e28) {
    }
  }
  return param_1;
}
