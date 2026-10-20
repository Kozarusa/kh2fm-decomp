#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" u32 func_0016c028(u32);
extern "C" f32 D_0036adb8;

void func_0013f828(int param_1)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  puVar1 = (u32 *)func_0016c028(*(u32 *)(param_1 + 0x44));
  if ((u32 *)(param_1 + 0x80) != puVar1) {
    uVar2 = puVar1[1];
    uVar3 = puVar1[2];
    uVar4 = puVar1[3];
    *(u32 *)(param_1 + 0x80) = *puVar1;
    *(u32 *)(param_1 + 0x84) = uVar2;
    *(u32 *)(param_1 + 0x88) = uVar3;
    *(u32 *)(param_1 + 0x8c) = uVar4;
  }
  *(float *)(param_1 + 0x84) = *(float *)(param_1 + 0x84) - D_0036adb8;
  return;
}

