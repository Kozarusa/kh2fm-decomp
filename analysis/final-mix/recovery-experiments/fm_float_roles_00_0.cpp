#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern s32 D_0032b91c;
extern u16 D_0032bae0;
extern s32 D_0033cc60;
extern s32 D_0033cc68;
extern s32 D_0033cc6c;
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
extern s32 D_00352130;
extern s16 D_00369da8;
extern f32 D_0036a8f8;
extern f32 D_0036a8fc;
extern f32 D_0036a900;
extern f32 D_0036a9e0;
extern f32 D_0036a9e4;
extern f32 D_0036a9e8;
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
extern f32 D_0036d034;
extern f32 D_0036d038;
extern f32 D_0036d03c;
extern f32 D_0036d040;
extern f32 D_0036d044;
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
extern s32 D_01c61b04;

void func_00134d10(u32 *param_1)

{
  f32 uVar1;
  f32 uVar2;
  
  *param_1 = 0;
  param_1[2] = 0;
  uVar1 = D_0036ac48;
((f32*)param_1)[7] = D_0036ac48;
((f32*)param_1)[3] = uVar1;
  uVar2 = D_0036ac4c;
((f32*)param_1)[4] = uVar1;
((f32*)param_1)[1] = uVar2;
((f32*)param_1)[5] = uVar1;
((f32*)param_1)[6] = uVar1;
  return;
}

void func_001676b0(u64 *param_1,u64 param_2)

{
  f32 uVar1;
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
*(f32*)(param_1 + 8) = uVar1;
    }
    return;
  }
  param_1[3] = uVar2;
*(f32*)(param_1 + 8) = uVar1;
  return;
}

void func_001957e8(u32 *param_1)

{
  f32 uVar1;
*(f32*)param_1 = D_0036d034;
((f32*)param_1)[1] = D_0036d038;
((f32*)param_1)[2] = D_0036d03c;
((f32*)param_1)[3] = D_0036d040;
  uVar1 = D_0036d044;
  param_1[4] = *(u32 *)(D_00352130 + 0x14);
((f32*)param_1)[6] = uVar1;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  return;
}
