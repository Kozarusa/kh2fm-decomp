#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern s32 D_0032b91c;
extern u16 D_0032bae0;
extern s32 D_0033cc60;
extern s32 D_0033cc68;
extern s32 D_0033cc6c;
extern f32 D_00340eb4;
extern f32 D_00340eb8;
extern f32 D_00340ebc;
extern f32 D_00340ec0;
extern s32 D_00347d64;
extern s32 D_00347f80;
extern s32 D_00347fb0;
extern s32 D_00347fb4;
extern s32 D_00347fd8;
extern s32 D_00347fdc;
extern s32 D_00347fe0;
extern s32 D_00347fe4;
extern f32 D_00349e10;
extern s32 D_0034a778;
extern s32 D_0034a77c;
extern f32 D_0034a780;
extern f32 D_0034a784;
extern f32 D_0034a788;
extern s32 D_0034a790;
extern u8 D_0034aa40;
extern s32 D_0034aa70;
extern s32 D_0034aa74;
extern s32 D_0034aa78;
extern s32 D_0034aa7c;
extern s32 D_0034aa80;
extern s32 D_0034c768;
extern s32 D_0034c76c;
extern s32 D_0034dca0;
extern s32 D_0034dca4;
extern s32 D_0034dcb8;
extern s32 D_0034dcbc;
extern s32 D_0034f240;
extern s16 D_00369da8;
extern f32 D_0036a3dc;
extern f32 D_0036a3e0;
extern f32 D_0036a8f8;
extern f32 D_0036a8fc;
extern f32 D_0036a900;
extern f32 D_0036a9e0;
extern f32 D_0036a9e4;
extern f32 D_0036a9e8;
extern f32 D_0036aa14;
extern f32 D_0036aa18;
extern f32 D_0036abec;
extern f32 D_0036abf0;
extern f32 D_0036ac48;
extern f32 D_0036ac4c;
extern f32 D_0036b200;
extern f32 D_0036b204;
extern f32 D_0036b210;
extern f32 D_0036b254;
extern f32 D_0036b31c;
extern f32 D_0036b320;
extern f32 D_0036b3fc;
extern f32 D_0036c584;
extern f32 D_0036cc20;
extern f32 D_0036ccd8;
extern s32 D_0038aa40;
extern s32 D_003a84d0;
extern f32 D_004f3580;
extern f32 D_004f3584;
extern f32 D_004f35a4;
extern f32 D_004f35a8;
extern s32 D_004f36a0;
extern f32 D_004f36a4;
extern s32 D_004f36f8;
extern f32 D_004f36fc;
extern s32 D_004f3750;
extern f32 D_004f3754;
extern s32 D_004f3b38;
extern s32 D_004f41c0;
extern u8 D_004f4240;
extern u8 D_004f4241;
extern s32 D_004f4244;
extern f32 D_004f526c;
extern f32 D_004f5270;
extern s32 D_004f6288;
extern s32 D_004f6290;
extern s32 D_004f6294;
extern s32 D_004f63a0;
extern s32 D_004f63a8;
extern s32 D_004f63ac;
extern s32 D_01c5f478;
extern f32 D_01c60520;
extern f32 D_01c6053c;
extern f32 D_01c60540;
extern s32 D_01c608c0;
extern f32 D_01c60be8;
extern f32 D_01c60cd0;
extern s32 D_01c60cd8;
extern s32 D_01c60cdc;

int func_00102210(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = D_0038aa40;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    iVar2 = iVar1;
    if (iVar2 == 0) break;
    if (*(int *)(iVar2 + 0x1c) == 1) {
      return iVar2;
    }
  }
  return 0;
}

short func_001033d8(short param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  sVar1 = -1;
  iVar2 = 0;
  if (-1 < D_00369da8) {
    psVar3 = &D_00369da8;
    do {
      if (*psVar3 == param_1) {
        sVar1 = psVar3[1];
      }
      iVar2 = iVar2 + 1;
      psVar3 = &D_00369da8 + iVar2 * 2;
    } while (-1 < (&D_00369da8)[iVar2 * 2]);
  }
  return sVar1;
}

u32 func_00109450(int param_1,int param_2,int param_3)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  int *piVar4;
  
  uVar1 = 1;
  if (param_3 == 0) {
    iVar2 = 0;
    puVar3 = &D_003a84d0;
    do {
      *puVar3 = 0;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 0x200);
  }
  else {
    param_2 = param_1 + param_2;
    if ((param_1 < param_2) && (param_1 < 0x200)) {
      piVar4 = &D_003a84d0 + param_1;
      iVar2 = *piVar4;
      while( true ) {
        param_1 = param_1 + 1;
        if (iVar2 != param_3) {
          *piVar4 = param_3;
          uVar1 = 0;
        }
        piVar4 = piVar4 + 1;
        if (param_2 <= param_1) break;
        if (0x1ff < param_1) {
          return uVar1;
        }
        iVar2 = *piVar4;
      }
    }
  }
  return uVar1;
}

int * func_00109c30(void)

{
  int *piVar1;
  u32 uVar2;
  int *piVar3;
  
  uVar2 = 0;
  piVar1 = (int *)0x0;
  piVar3 = D_0033cc6c;
  if (D_0033cc68 != 0) {
    do {
      if ((*piVar3 == 0) && (piVar3[1] == D_0033cc60)) break;
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 0x16;
    } while (uVar2 < D_0033cc68);
  }
  if (uVar2 < D_0033cc68) {
    piVar1 = D_0033cc6c + uVar2 * 0x16;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[4] = 0;
    piVar1[0x14] = 0;
    piVar1[0x15] = 0;
  }
  return piVar1;
}

void func_0010a828(float param_1,float param_2)

{
  D_00340eb8 = param_2;
  D_00340eb4 = param_1;
  D_00340ec0 = (param_2 * D_0036a3dc) / (param_2 - param_1);
  D_00340ebc = D_0036a3e0 / (param_2 - param_1);
  return;
}

float func_0011c050(float param_1)

{
  if (0.0 < param_1) {
    for (; D_0036a8f8 < param_1; param_1 = param_1 - D_0036a8fc) {
    }
  }
  else {
    for (; param_1 < D_0036a900; param_1 = param_1 + D_0036a8fc) {
    }
  }
  return param_1;
}

float func_00127de8(float param_1)

{
  if (0.0 < param_1) {
    for (; D_0036a9e0 < param_1; param_1 = param_1 - D_0036a9e4) {
    }
  }
  else {
    for (; param_1 < D_0036a9e8; param_1 = param_1 + D_0036a9e4) {
    }
  }
  return param_1;
}

float func_001286d0(float param_1,float param_2,float param_3,float param_4,float param_5,
                  float param_6,float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  param_1 = param_1 - param_2;
  fVar4 = D_0036aa14 / (param_5 - param_2);
  fVar2 = param_1 * param_1;
  fVar3 = fVar2 * fVar4;
  fVar1 = fVar2 * param_1 * fVar4 * fVar4;
  fVar2 = fVar2 * D_0036aa18 * fVar4 * fVar4;
  fVar4 = (fVar1 + fVar1) * fVar4;
  return param_7 * (fVar1 - fVar3) +
         param_4 * ((fVar1 - (fVar3 + fVar3)) + param_1) +
         param_6 * (fVar2 - fVar4) + param_3 * ((fVar4 - fVar2) + D_0036aa14);
}

int func_001317a8(float param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0x24);
  iVar2 = (int)((param_1 * *(float *)(*(int *)(param_2 + 4) + 0x58)) / D_0036abec + D_0036abf0);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar1 <= iVar2) {
    iVar2 = iVar1 + -1;
  }
  return iVar2;
}

void func_00134d10(u32 *param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = 0;
  param_1[2] = 0;
  uVar1 = D_0036ac48;
  param_1[7] = D_0036ac48;
  param_1[3] = uVar1;
  uVar2 = D_0036ac4c;
  param_1[4] = uVar1;
  param_1[1] = uVar2;
  param_1[5] = uVar1;
  param_1[6] = uVar1;
  return;
}

void func_00138190(u32 param_1,u32 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = D_00347d64;
  iVar1 = *(int *)(D_00347d64 + 0x30);
  iVar2 = iVar1 + 1;
  iVar4 = iVar1 - *(int *)(D_00347d64 + 0x34);
  iVar3 = iVar4 + 8;
  iVar5 = iVar1 + 8;
  if (-1 < iVar2) {
    iVar5 = iVar2;
  }
  iVar4 = iVar4 + 0xf;
  if (-1 < iVar3) {
    iVar4 = iVar3;
  }
  if (iVar3 + (iVar4 >> 3) * -8 < 7) {
    *(int *)(D_00347d64 + 0x30) = iVar2 + (iVar5 >> 3) * -8;
    iVar6 = iVar6 + iVar1 * 0x530;
    *(u32 *)(iVar6 + 0x564) = param_2;
    *(u32 *)(iVar6 + 0x560) = param_1;
  }
  return;
}

u32 func_00139d78(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  *(int *)(D_00347f80 + 100) = param_1;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(D_00347f80 + 4);
    }
    else {
      iVar1 = *(int *)(iVar1 + 4);
    }
    if (iVar1 == 0) break;
    if (iVar1 == param_1) {
      return 1;
    }
  }
  return 0;
}

void func_0013a820(int param_1,s64 param_2)

{
  int iVar1;
  u32 *puVar2;
  
  if (param_2 == 0xffff) {
    if (param_1 == 1) {
      iVar1 = 3;
      puVar2 = &D_00347fb0;
      D_00347fb0 = 0;
      D_00347fb4 = 0;
      do {
        puVar2[2] = 0;
        iVar1 = iVar1 + -1;
        puVar2[3] = 0;
        puVar2 = puVar2 + 2;
      } while (-1 < iVar1);
    }
    if (param_1 == 1) {
      D_00347fd8 = 0;
      D_00347fdc = 0;
      D_00347fe4 = 0;
      D_00347fe0 = 0;
    }
  }
  return;
}

void func_0014ec40(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_004f3580 = D_0036b200;
    D_004f3584 = D_0036b204;
  }
  return;
}

void func_0014f030(float param_1,float param_2,float param_3,float *param_4)

{
  float fVar1;
  
  fVar1 = D_0036b210;
  if (param_3 != 0.0) {
    fVar1 = param_3;
  }
  *param_4 = param_1;
  param_4[2] = param_2;
  param_4[1] = (param_2 - param_1) / fVar1;
  return;
}

float func_00153610(float param_1)

{
  float fVar1;
  
  fVar1 = D_0036b254 / (D_0034a788 * param_1 * param_1 + D_0034a780 + D_0034a784 * param_1);
  if (D_0036b254 < fVar1) {
    fVar1 = D_0036b254;
  }
  if (fVar1 < 0.0) {
    fVar1 = 0.0;
  }
  return fVar1;
}

void func_001538d8(u32 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  
  iVar1 = D_0034a77c;
  if (D_0034a790 != 0) {
    iVar2 = 0;
    if (0 < D_0034a77c) {
      iVar3 = 0;
      do {
        puVar4 = (u32 *)(iVar3 + D_0034a778);
        iVar3 = iVar3 + 0x18;
        if (*puVar4 == (param_1 & 0xff)) {
          *(u8 *)(iVar2 * 0x40 + D_0034a790 + 0x30) = 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return;
}

void func_00153948(u32 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  
  iVar1 = D_0034a77c;
  if (D_0034a790 != 0) {
    iVar2 = 0;
    if (0 < D_0034a77c) {
      iVar3 = 0;
      do {
        puVar4 = (u32 *)(iVar3 + D_0034a778);
        iVar3 = iVar3 + 0x18;
        if (*puVar4 == (param_1 & 0xff)) {
          *(u8 *)(iVar2 * 0x40 + D_0034a790 + 0x30) = 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return;
}

void func_00158fd8(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_004f35a4 = D_0036b31c;
    D_004f35a8 = D_0036b320;
  }
  return;
}

void func_0015a6c8(u32 *param_1)

{
  D_0034aa70 = *param_1;
  D_0034aa74 = param_1[1];
  D_0034aa78 = param_1[2];
  D_0034aa7c = param_1[3];
  D_0034aa40 = 1;
  D_0034aa80 = param_1[4];
  return;
}

void func_0015ccf0(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_004f36a0 = 0;
    D_004f36a4 = D_0036b3fc;
    D_004f36f8 = 0;
    D_004f36fc = D_0036b3fc;
  }
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_004f3750 = 0;
    D_004f3754 = D_0036b3fc;
  }
  return;
}

int func_00161030(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  while( true ) {
    iVar1 = D_004f3b38;
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 0x80);
    }
    iVar3 = iVar1;
    if (iVar3 == 0) break;
    if (*(int *)(iVar3 + 0x1b0) == 0) {
      if (iVar2 == param_1) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return 0;
}

void func_00161a58(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x80 < param_1) {
    param_1 = 0x80;
  }
  D_0034c768 = param_1;
  return;
}

void func_00161a80(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x80 < param_1) {
    param_1 = 0x80;
  }
  D_0034c76c = param_1;
  return;
}

void func_00165ef0(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = D_004f41c0;
    if (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
  } while ((iVar1 != 0) && (param_1 = iVar1, (*(u32 *)(iVar1 + 8) & 2) != 0));
  return;
}

void func_001671e8(int param_1,u8 param_2)

{
  if (param_1 < 15000) {
    param_1 = 15000;
  }
  D_004f4241 = param_2;
  D_004f4240 = 1;
  D_004f4244 = param_1;
  return;
}

void func_001676b0(u64 *param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  u64 uVar3;
  float fVar4;
  
  uVar3 = *param_1;
  param_1[3] = 0;
  *param_1 = param_2;
  uVar2 = (uVar3 ^ param_2) & param_2;
  param_1[2] = (uVar3 ^ param_2) & ~param_2;
  param_1[1] = uVar2;
  uVar1 = D_004f526c;
  if (uVar2 == 0) {
    if ((param_2 != 0) &&
       (fVar4 = *(float *)(param_1 + 8) - D_00349e10, *(float *)(param_1 + 8) = fVar4,
       uVar1 = D_004f5270, fVar4 <= 0.0)) {
      param_1[3] = param_2;
      *(u32 *)(param_1 + 8) = uVar1;
    }
    return;
  }
  param_1[3] = uVar2;
  *(u32 *)(param_1 + 8) = uVar1;
  return;
}

void func_0016d230(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_004f6288 = D_0032b91c;
    D_004f6290 = 0;
    D_004f6294 = 0;
  }
  return;
}

void func_0016f7b0(void)

{
  D_004f63a8 = 0;
  D_004f63a0 = 0;
  D_004f63ac = 0;
  return;
}

int func_0016f930(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  piVar1 = &D_004f63a8;
  iVar3 = 0x96a;
  iVar4 = D_004f63a8;
  while( true ) {
    piVar1 = piVar1 + 1;
    if (iVar4 == param_1) {
      return iVar3;
    }
    iVar2 = iVar2 + 1;
    if (1 < iVar2) break;
    iVar4 = *piVar1;
    iVar3 = iVar3 + 10;
  }
  return 0x960;
}

int func_001702e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = D_0034dca0;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x3c);
    }
    iVar2 = iVar1;
    if (iVar2 == 0) break;
    if (*(int *)(iVar2 + 0x30) == param_1) {
      return iVar2;
    }
  }
  return 0;
}

u32 func_00170d38(s64 param_1)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  uVar1 = 1;
  if ((((param_1 != 0x3f2) && (uVar1 = 2, 99 < iVar2 - 0x8fcU)) && (uVar1 = 3, 9 < iVar2 - 0x96aU))
     && (((uVar1 = 4, 9 < iVar2 - 0x974U && (uVar1 = 5, 99 < iVar2 - 5000U)) &&
         ((99 < iVar2 - 0x13ecU || (uVar1 = 6, D_01c5f478 < 1)))))) {
    uVar1 = 0;
  }
  return uVar1;
}

void func_00170ee8(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_0034dca0 = 0;
    D_0034dca4 = 0;
    D_0034dcb8 = 0;
    D_0034dcbc = 0;
  }
  return;
}

void func_0017e808(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01c60520 = D_0036c584;
  }
  return;
}

float func_001826f8(void)

{
  return D_01c60540 / D_01c6053c;
}

void func_00188470(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 0x88);
  iVar3 = 0;
  piVar2 = &D_01c608c0;
  do {
    if (*piVar2 == 0) {
      piVar2[2] = param_1;
      *piVar2 = param_3;
      piVar2[1] = iVar1;
      return;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 3;
  } while (iVar3 < 0x40);
  return;
}

void func_0018c868(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01c60be8 = D_0036cc20;
  }
  return;
}

u32 func_0018f070(int param_1)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      iVar3 = D_01c60cd8;
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0xc0);
      }
      if (iVar3 == 0) {
        return 0;
      }
      uVar1 = 1;
      iVar2 = iVar3;
    } while (iVar3 != param_1);
  }
  return uVar1;
}

void func_0018f0b0(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01c60cd0 = D_0036ccd8;
    D_01c60cd8 = 0;
    D_01c60cdc = 0;
  }
  return;
}

u32 func_00191c50(void)

{
  u32 uVar1;
  
  uVar1 = 0;
  if ((D_0032bae0 == 0x1712) || ((D_0034f240 & 0x2000) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}
