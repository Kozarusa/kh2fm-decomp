#include "../common/types.h"
// Provisional recovery; complete-range proof is required.

void func_00148638(float param_1,u64 param_2,int param_3)

{
  int iVar1;
  u8 uVar2;
  
  iVar1 = *(int *)(param_3 + 0x114);
  uVar2 = 2;
  if ((((param_1 <= *(float *)(iVar1 + 0x44)) &&
       (uVar2 = *(u8 *)(param_3 + 0x10d), param_1 <= *(float *)(iVar1 + 0x40))) &&
      (uVar2 = 1, param_1 <= *(float *)(iVar1 + 0x3c))) &&
     (uVar2 = *(u8 *)(param_3 + 0x10d), param_1 <= *(float *)(iVar1 + 0x38))) {
    uVar2 = 0;
  }
  *(u8 *)(param_3 + 0x10d) = uVar2;
  return;
}

