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

void func_001d37a0(u32 param_1,u32 *param_2,u32 *param_3)

{
  f32 uVar1;
  u32 uVar2;
  u32 uVar3;
  
  uVar1 = param_3[1];
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *param_2 = *param_3;
((f32*)param_2)[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[8] = param_1;
  param_2[4] = 0;
  uVar1 = D_0036e430;
  param_2[5] = 0;
((f32*)param_2)[10] = uVar1;
  param_2[6] = param_1;
  uVar1 = D_0036e434;
  param_2[7] = param_1;
((f32*)param_2)[0xb] = uVar1;
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
