#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern u16 D_0032f218;
extern u16 D_0032fb00;
extern u8 D_0032fb88;
extern u8 D_0032fc87;
extern f32 D_00349e10;
extern s32 D_00350444;
extern s32 D_00350448;
extern f32 D_00350464;
extern f32 D_00350468;
extern s32 D_00350f18;
extern s32 D_00350f1c;
extern u8 D_003511c2;
extern u8 D_003511c3;
extern s32 D_00352130;
extern f32 D_0036d4e4;
extern f32 D_0036d7a4;
extern f32 D_0036e164;
extern f32 D_0036e168;
extern f32 D_0036e16c;
extern f32 D_0036e2ec;
extern f32 D_0036e360;
extern f32 D_0036e3f8;
extern f32 D_0036e430;
extern f32 D_0036e434;
extern u32* D_01c61b08;
extern s32 D_01c61b48;
extern f32 D_01c6cb18;
extern s32 D_01c6cb98;
extern s32 D_01c6cba0;
extern s32 D_01c6cba4;
extern s32 D_01c6ced0;
extern s32 D_01c6ced4;
extern s32 D_01c94090;
extern s32 D_01c94094;
extern s32 D_01d48c80;
extern s32 D_01d48c84;
extern int* D_01d48cb0;
extern s32 D_01d48da0;
extern s32 D_01d48da4;
extern s32 D_01d49320;
extern s32 D_01d49328;
extern s32 D_01d49348;
extern s32 D_01d4934c;
extern s32 D_01d49350;
extern s32 D_01d49354;
extern u16 D_01d49388;
extern s32 D_01d49530;
extern s32 D_01d49550;
extern u8 D_01d49570;
extern u8 D_01d49571;
extern u8 D_01d49572;
extern u16 D_01d49574;
extern u16 D_01d49576;
extern u16 D_01d49578;
extern s32 D_01d49960;
extern s32 D_01d49964;
extern s32 D_01d49968;
extern s32 D_01d5b9e0;
extern s32 D_01d5b9e4;
extern s32 D_01d5b9e8;
extern s32 D_01d5b9f0;
extern s32 D_01d5b9f4;
extern f32 D_01d5b9f8;
extern f32 D_01d5ba08;
extern s32 D_01d5ba20;
extern u32* D_01d5ba24;
extern s32 D_01d5ba28;
extern s32 D_01d5ba98;
extern s32 D_01d5baa8;

int func_00196618(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (*D_01c61b08 != 0) {
    iVar2 = 0;
    do {
      if ((*(u8 *)((int)D_01c61b08 + iVar2 + 2) == param_1) &&
         (*(u8 *)((int)D_01c61b08 + iVar2 + 3) == param_2)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar1 * 2;
    } while (iVar1 < (int)(u32)*D_01c61b08);
  }
  return -1;
}

int * func_00198bd0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  piVar2 = &D_01c61b48;
  iVar3 = D_01c61b48;
  while( true ) {
    if (iVar3 == param_1) {
      if (piVar2[1] == param_2) {
        return piVar2;
      }
      if ((param_2 < 0) || (piVar2[1] < 0)) {
        piVar1 = piVar2;
      }
    }
    piVar2 = piVar2 + 0x16;
    if (0x1c620c7 < (int)piVar2) break;
    iVar3 = *piVar2;
  }
  return piVar1;
}

int func_0019d380(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(D_00350444 + 0x20);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (*(int *)(D_00350444 + 4) == param_1) {
    if (*(int *)(D_00350444 + 0x24) != param_2) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

void func_0019ee28(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_00350468 = 0;
    D_00350448 = 0;
    D_00350464 = 0;
  }
  return;
}

void func_001a5b08(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01c6cb18 = D_0036d4e4;
  }
  return;
}

int func_001a81f0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = D_01c6cb98 + 4;
  if (*(u16 *)(D_01c6cb98 + 2) != 0) {
    do {
      if ((((*(char *)(iVar2 + 4) == '\0') && (*(u8 *)(iVar2 + 5) == param_1)) &&
          (*(u8 *)(iVar2 + 6) == param_2)) && (*(u8 *)(iVar2 + 7) == param_3)) {
        return iVar2;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar1 < (int)(u32)*(u16 *)(D_01c6cb98 + 2));
  }
  return 0;
}

u32 func_001a82b0(s64 param_1)

{
  u32 uVar1;
  
  if (param_1 == 0) {
    return D_01c6cb98 + 4;
  }
  uVar1 = (int)param_1 + 0xc;
  if (D_01c6cb98 + (u32)*(u16 *)(D_01c6cb98 + 2) * 0xc + 4 <= uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}

int func_001a8510(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (D_01c6cba0 - D_01c6cba4) + 8;
  iVar2 = (D_01c6cba0 - D_01c6cba4) + 0xf;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  return iVar1 + (iVar2 >> 3) * -8;
}

void func_001ad948(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01c6ced0 = 0;
    D_01c6ced4 = 0;
  }
  return;
}

u32 func_001ad9c8(float *param_1)

{
  float fVar1;
  u32 uVar2;
  float fVar3;
  
  uVar2 = 0;
  if (param_1[1] != 0.0) {
    fVar3 = *param_1 + param_1[1] * D_00349e10;
    *param_1 = fVar3;
    fVar1 = D_0036d7a4;
    if (fVar3 <= 0.0) {
      param_1[1] = 0.0;
      *param_1 = 0.0;
    }
    else {
      if (fVar3 < D_0036d7a4) {
        return 1;
      }
      param_1[1] = 0.0;
      *param_1 = fVar1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

void func_001afa50(void)

{
  u32 *puVar1;
  
  puVar1 = &D_01c94090;
  D_01c94090 = 0;
  while( true ) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1 = puVar1 + 3;
    if (0x1c940b3 < (int)puVar1) break;
    *puVar1 = 0;
  }
  return;
}

int func_001afe30(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = &D_01c94094;
  iVar3 = D_01c94094;
  iVar2 = 0;
  while( true ) {
    piVar1 = piVar1 + 3;
    if (iVar3 == param_1) {
      return iVar2;
    }
    if (2 < iVar2 + 1) break;
    iVar3 = *piVar1;
    iVar2 = iVar2 + 1;
  }
  return -1;
}

bool func_001b1fc8(int param_1)

{
  return D_00350f18 == 0 && D_00350f1c == param_1;
}

void func_001b26e0(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01d48c80 = 0;
    D_01d48c84 = 0;
  }
  return;
}

u16 func_001b5af0(void)

{
  if ((D_01d48cb0 != (int *)0x0) && ((D_01d48cb0[0x10] & 4U) == 0)) {
    return *(u16 *)(*D_01d48cb0 + 0x28);
  }
  return 0;
}

bool func_001b7fd0(void)

{
  return D_003511c3 == '\0' && D_003511c2 == '\x01';
}

void func_001b8d60(int param_1)

{
  u8 *puVar1;
  u32 uVar2;
  int iVar3;
  u8 *puVar4;
  
  iVar3 = 0;
  uVar2 = (u32)D_0032fc87;
  D_0032fc87 = 0;
  if (uVar2 != 0) {
    do {
      puVar4 = (u8 *)(param_1 + iVar3);
      puVar1 = &D_0032fb88 + iVar3;
      iVar3 = iVar3 + 1;
      *puVar4 = *puVar1;
    } while (iVar3 < (int)uVar2);
  }
  return;
}

void func_001b9380(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2;
    iVar2 = D_01d48da0;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x8b4);
    }
  } while ((iVar2 != 0) && (*(u8 *)(iVar2 + 0x9ad) < *(u8 *)(param_1 + 0x9ad)));
  if (iVar1 != 0) {
    if (iVar1 == D_01d48da4) {
      *(int *)(iVar1 + 0x8b4) = param_1;
      *(u32 *)(param_1 + 0x8b4) = 0;
      D_01d48da4 = param_1;
      return;
    }
    *(u32 *)(param_1 + 0x8b4) = *(u32 *)(iVar1 + 0x8b4);
    *(int *)(iVar1 + 0x8b4) = param_1;
    return;
  }
  if (D_01d48da0 != 0) {
    *(int *)(param_1 + 0x8b4) = D_01d48da0;
    D_01d48da0 = param_1;
    return;
  }
  D_01d48da0 = param_1;
  D_01d48da4 = param_1;
  *(u32 *)(param_1 + 0x8b4) = 0;
  return;
}

u32 func_001ba028(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = D_01d48da0;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x8b4);
    }
    if (iVar2 == 0) break;
    iVar1 = iVar2;
    if (iVar2 == param_1) {
      return 1;
    }
  }
  return 0;
}

bool func_001bbb28(void)

{
  bool bVar1;
  
  bVar1 = false;
  if (D_01d49320 != 0) {
    bVar1 = (*(u16 *)(*(int *)(D_01d49320 + 8) + 4) & 0x400) != 0;
  }
  return bVar1;
}

u32 func_001bbb50(void)

{
  u8 bVar1;
  
  if (D_01d49320 == 0) {
    return 0;
  }
  bVar1 = *(u8 *)(*(int *)(D_01d49320 + 8) + 8);
  if (bVar1 != 0x19) {
    if (bVar1 < 0x1a) {
      if (bVar1 != 2) {
        return 0;
      }
    }
    else if (bVar1 != 0x20) {
      return 0;
    }
  }
  return 1;
}

u32 func_001bdd20(int param_1)

{
  u32 uVar1;
  
  uVar1 = 0;
  if (((*(u32 *)(param_1 + 0x20) & 0x10) != 0) || (D_0032f218 == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

void func_001bff88(void)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = 7;
  puVar2 = &D_01d49328;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  D_01d4934c = 0x100;
  D_01d49348 = 0;
  D_01d49350 = 0;
  D_01d49354 = 0;
  return;
}

int func_001c0090(void)

{
  D_01d4934c = D_01d4934c + 1;
  if (0x10000000 < D_01d4934c) {
    D_01d4934c = 0x100;
  }
  return D_01d4934c;
}

void func_001c05b0(int param_1,s64 param_2)

{
  int iVar1;
  u32 *puVar2;
  
  if (param_2 == 0xffff) {
    if (param_1 == 1) {
      iVar1 = 7;
      puVar2 = &D_01d49328;
      do {
        *puVar2 = 0;
        iVar1 = iVar1 + -1;
        puVar2 = puVar2 + 1;
      } while (-1 < iVar1);
    }
    if (param_1 == 1) {
      D_01d49350 = 0;
      D_01d49354 = 0;
    }
  }
  return;
}

void func_001c10c8(void)

{
  int iVar1;
  u16 *puVar2;
  
  iVar1 = 5;
  puVar2 = &D_01d49388;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 0x20;
  } while (-1 < iVar1);
  return;
}

void func_001c2b70(void)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = 7;
  puVar2 = &D_01d49530;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  D_01d49550 = 0;
  return;
}

void func_001c4080(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01d49570 = 0xff;
    D_01d49571 = 0xff;
    D_01d49572 = 0xff;
    D_01d49574 = 0xffff;
    D_01d49576 = 0xffff;
    D_01d49578 = 0xffff;
  }
  return;
}

void func_001c8a90(void)

{
  D_01d49960 = 0;
  D_01d49964 = 0;
  D_01d49968 = 0;
  return;
}

float func_001cbf50(float param_1)

{
  if (0.0 < param_1) {
    for (; D_0036e164 < param_1; param_1 = param_1 - D_0036e168) {
    }
  }
  else {
    for (; param_1 < D_0036e16c; param_1 = param_1 + D_0036e168) {
    }
  }
  return param_1;
}

void func_001ce668(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01d5b9e0 = 0;
    D_01d5b9e8 = 0;
    D_01d5b9e4 = 0;
    D_01d5b9f0 = 0;
    D_01d5b9f4 = 0;
    D_01d5b9f8 = D_0036e2ec;
  }
  return;
}

void func_001cfac0(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  param_2 = param_2 * D_0036e360;
  param_3 = param_3 * D_0036e360;
  param_4 = param_4 * D_0036e360;
  *(float *)(param_5 + 0xb90) = param_1 * D_0036e360;
  *(float *)(param_5 + 0xb94) = param_2;
  *(float *)(param_5 + 0xb98) = param_3;
  *(float *)(param_5 + 0xb9c) = param_4;
  return;
}

float func_001d3000(float param_1)

{
  float fVar1;
  
  if (*(float *)(D_00352130 + 0xf8) <= param_1) {
    return *(float *)(D_00352130 + 0xf0);
  }
  fVar1 = *(float *)(D_00352130 + 0xfc);
  if (fVar1 < param_1) {
    return *(float *)(D_00352130 + 0xf4) +
           (*(float *)(D_00352130 + 0xf0) - *(float *)(D_00352130 + 0xf4)) *
           ((param_1 - fVar1) / (*(float *)(D_00352130 + 0xf8) - fVar1));
  }
  return *(float *)(D_00352130 + 0xf4);
}

void func_001d3060(int param_1,s64 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01d5ba08 = D_0036e3f8;
  }
  return;
}

void func_001d37a0(u32 param_1,u32 *param_2,u32 *param_3)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *param_2 = *param_3;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[8] = param_1;
  param_2[4] = 0;
  uVar1 = D_0036e430;
  param_2[5] = 0;
  param_2[10] = uVar1;
  param_2[6] = param_1;
  uVar1 = D_0036e434;
  param_2[7] = param_1;
  param_2[0xb] = uVar1;
  param_2[9] = 0;
  if (D_01d5ba24 != (u32 *)0x0) {
    *(u32 **)((int)D_01d5ba24 + 0x30) = param_2;
    param_2[0xc] = 0;
    D_01d5ba24 = param_2;
    return;
  }
  D_01d5ba20 = param_2;
  D_01d5ba24 = param_2;
  param_2[0xc] = 0;
  return;
}

int func_001d44d8(u64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(D_01d5ba28 + 4)) {
    do {
      iVar2 = iVar1 * 0x40;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + D_01d5ba28;
      if (*(u16 *)(iVar2 + 0x30) == param_1) {
        return iVar2 + 8;
      }
    } while (iVar1 < *(int *)(D_01d5ba28 + 4));
  }
  return 0;
}

u32 func_001d6cc8(s64 param_1)

{
  u32 uVar1;
  
  if (param_1 == 0) {
    return D_01d5ba98 + 8;
  }
  uVar1 = (int)param_1 + 0x40;
  if (D_01d5ba98 + *(int *)(D_01d5ba98 + 4) * 0x40 + 8U <= uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}

void func_001d97c8(void)

{
  if (D_0032fb00 < 999) {
    D_0032fb00 = D_0032fb00 + 1;
  }
  return;
}

int func_001d9dd0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = D_01d5baa8 + 8;
  if (0 < *(int *)(D_01d5baa8 + 4)) {
    do {
      if (((*(u8 *)(iVar2 + 4) == param_1) && (*(u8 *)(iVar2 + 5) == param_2)) &&
         (*(u8 *)(iVar2 + 6) == param_3)) {
        return iVar2;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 10;
    } while (iVar1 < *(int *)(D_01d5baa8 + 4));
  }
  return 0;
}

u32 func_001d9e30(s64 param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  if (param_1 == 0) {
    return D_01d5baa8 + 8;
  }
  uVar2 = (int)param_1 + 10;
  uVar1 = 0;
  if (uVar2 < D_01d5baa8 + *(int *)(D_01d5baa8 + 4) * 10 + 8U) {
    uVar1 = uVar2;
  }
  return uVar1;
}
