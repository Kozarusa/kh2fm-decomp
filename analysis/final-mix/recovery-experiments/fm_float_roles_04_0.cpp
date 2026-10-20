#include "../common/types.h"

// Provisional scalar globals inferred from original memory operations.
extern u32* D_0035f230;
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
extern u32* D_0036712c;
extern s32 D_00367130;
extern f32 D_0036c238;
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
extern s32 D_01e357e4;
extern s32 D_01e357ec;

void func_002e3f78(u32 *param_1)

{
  f32 uVar1;
  
  uVar1 = D_00375f78;
  *param_1 = 0;
((f32*)param_1)[3] = uVar1;
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}

void func_002e4a08(u32 *param_1)

{
*(f32*)param_1 = D_00375fb8;
((f32*)param_1)[1] = D_00375fbc;
  return;
}

void func_002eac70(f32 param_1,f32 param_2,f32 param_3,f32 param_4)

{
  D_00363440 = param_1;
  D_00363448 = param_2;
  D_0036344c = param_3;
  D_00363450 = param_4;
  return;
}

void func_0031e268(int param_1)

{
  f32 uVar1;
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
*(f32*)(puVar2 + 4) = uVar1;
    *(u32 *)(puVar2 + 8) = 0;
    puVar2 = puVar2 + 0x10;
  } while (iVar3 != -1);
  return;
}
