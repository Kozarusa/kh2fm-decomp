#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern f32 D_00362d80;
extern f32 D_00362d84;
extern f32 D_00362d88;
extern f32 D_00362d8c;
extern f32 D_00362e70;
extern f32 D_00362e74;
extern f32 D_00362e78;
extern f32 D_00362e7c;
extern f32 D_00363440;
extern f32 D_00363448;
extern f32 D_0036344c;
extern f32 D_00363450;
extern f32 D_003634f0;
extern s32 D_00367120;
extern s32 D_00367124;
extern s32 D_00367128;
extern s32 D_0036712c;
extern s32 D_00367130;
extern f32 D_0036c238;
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
extern f32 D_00375f50;
extern f32 D_00375f78;
extern f32 D_00375fb8;
extern f32 D_00375fbc;
extern f32 D_003760d4;
extern f32 D_003760dc;
extern f32 D_00376180;
extern f32 D_00376184;
extern s32 D_01e2bfa0;
extern s32 D_01e2bfa4;
extern f32 D_01e2c040;
extern f32 D_01e2c044;
extern f32 D_01e2c048;
extern s32 D_01e2fe48;
extern s32 D_01e357e4;
extern s32 D_01e357ec;

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

void func_002e1878(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_00362d80 = 0;
    D_00362d8c = 0;
    D_00362d84 = 0;
    D_00362d88 = D_00375ef8;
  }
  return;
}

void func_002e2e50(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_00362e70 = 0;
    D_00362e7c = 0;
    D_00362e74 = 0;
    D_00362e78 = D_00375f50;
  }
  return;
}

void func_002e3f78(u32 *param_1)

{
  u32 uVar1;
  
  uVar1 = D_00375f78;
  *param_1 = 0;
  param_1[3] = uVar1;
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}

void func_002e4a08(u32 *param_1)

{
  *param_1 = D_00375fb8;
  param_1[1] = D_00375fbc;
  return;
}

void func_002e98b0(int param_1)

{
  int iVar1;
  
  D_01e2bfa4 = D_01e2bfa4 + -1;
  param_1 = param_1 - D_01e2bfa0;
  iVar1 = *(int *)(D_01e2bfa0 + 0x7f8) * 4 + D_01e2bfa0;
  *(int *)(D_01e2bfa0 + 0x7f8) = *(int *)(D_01e2bfa0 + 0x7f8) + 1;
  *(int *)(iVar1 + 0x780) = param_1 >> 6;
  return;
}

void func_002eac70(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  D_00363440 = param_1;
  D_00363448 = param_2;
  D_0036344c = param_3;
  D_00363450 = param_4;
  return;
}

void func_002ead48(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_00363448 = D_003760d4;
  }
  return;
}

void func_002eaee8(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_003634f0 = D_003760dc;
  }
  return;
}

void func_002eccd0(int param_1,s32 param_2)

{
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01e2c040 = D_00376180;
    D_01e2c044 = D_00376184;
  }
  if ((param_2 == 0xffff) && (param_1 == 1)) {
    D_01e2c048 = D_00376184;
  }
  return;
}

u32 func_002f5c70(void)

{
  u32 *puVar1;
  
  ram0x00363d28 = 1;
  puVar1 = &D_01e2fe48;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = puVar1 + 0xcd;
  } while ((int)puVar1 < 0x1e33188);
  return 1;
}

void func_003086b8(u32 param_1,u32 param_2,u32 param_3)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  
  if ((int)param_1 < 0) {
    iVar3 = (param_1 & 0x7fffffff) * 0xc;
    puVar1 = (u32 *)(iVar3 + D_01e357e4);
    puVar1[1] = param_3;
    *puVar1 = param_2;
    iVar2 = D_01e357e4;
  }
  else {
    iVar3 = param_1 * 0xc;
    puVar1 = (u32 *)(iVar3 + D_01e357ec);
    puVar1[1] = param_3;
    *puVar1 = param_2;
    iVar2 = D_01e357ec;
  }
  *(u32 *)(iVar3 + iVar2 + 8) = 0;
  return;
}

void func_00308730(u32 param_1)

{
  if ((int)param_1 < 0) {
    *(u32 *)((param_1 & 0x7fffffff) * 0xc + D_01e357e4) = 0;
    return;
  }
  *(u32 *)(param_1 * 0xc + D_01e357ec) = 0;
  return;
}

int func_0030fc28(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = iVar1;
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = iVar1;
    iVar2 = D_00367130;
  }
  D_00367130 = iVar2;
  if (iVar1 == 0) {
    param_1[1] = 0;
  }
  else {
    *(int *)(iVar1 + 4) = param_1[1];
    param_1[1] = 0;
  }
  return iVar1;
}

u32 func_0030ffd8(void)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  
  puVar2 = D_0036712c;
  if (D_0036712c == (u32 *)0x0) {
    return 0x80008005;
  }
  uVar3 = (int)D_0036712c << 4;
  D_00367128 = D_00367128 + 1;
  D_0036712c[10] = 0;
  D_0036712c[3] = 0;
  puVar1 = (u32 *)(D_0036712c + 6);
  D_0036712c = (u32 *)*D_0036712c;
  *puVar1 = 0;
  D_00367124 = D_00367124 + 1;
  puVar2[2] = (D_00367124 & 0x1ff) << 1 | 1;
  return uVar3 | puVar2[2];
}

u32 func_00310180(s32 param_1,s32 param_2)

{
  if (D_00367120 < 0) {
    return 0x80008001;
  }
  if (param_1 != 0) {
    *(int *)param_1 = D_00367128;
  }
  if (param_2 != 0) {
    *(int *)param_2 = 0x80 - D_00367128;
  }
  return 0;
}

void func_0031e268(int param_1)

{
  u32 uVar1;
  u8 *puVar2;
  int iVar3;
  
  uVar1 = D_0036c238;
  puVar2 = (u8 *)(param_1 + 4);
  iVar3 = 7;
  do {
    *(u32 *)(puVar2 + -4) = 0;
    iVar3 = iVar3 + -1;
    *puVar2 = 0x80;
    puVar2[1] = 0x80;
    puVar2[2] = 0x80;
    puVar2[3] = 0x80;
    *(u32 *)(puVar2 + 4) = uVar1;
    *(u32 *)(puVar2 + 8) = 0;
    puVar2 = puVar2 + 0x10;
  } while (iVar3 != -1);
  return;
}
