#include "../common/types.h"
// Provisional recovery; complete-range proof is required.
extern "C" s32 D_003a99f0;

void func_00148a68(int param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  
  uVar2 = (u32)*(u8 *)(param_2 + 0x11f);
  piVar3 = &D_003a99f0 + uVar2;
  iVar1 = *piVar3;
  while (iVar1 != 0) {
    piVar3 = piVar3 + 1;
    uVar2 = uVar2 + 1;
    iVar1 = *piVar3;
  }
  (&D_003a99f0)[uVar2] = param_2;
  *(int *)(param_1 + 0x537c) = *(int *)(param_1 + 0x537c) + 1;
  return;
}

