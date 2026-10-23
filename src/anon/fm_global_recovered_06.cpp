#include "../common/types.h"

// Preserve original registry aliases.
int func_001c0090(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");

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

bool func_001b1fc8(int param_1)

{
  return D_00350f18 == 0 && D_00350f1c == param_1;
}

bool func_001b7fd0(void)

{
  return D_003511c3 == '\0' && D_003511c2 == '\x01';
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

int func_001c0090(void)

{
  D_01d4934c = D_01d4934c + 1;
  if (0x10000000 < D_01d4934c) {
    D_01d4934c = 0x100;
  }
  return D_01d4934c;
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
