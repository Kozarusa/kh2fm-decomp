#include "../common/types.h"

void func_001e7230(u32 *param_1,u32 param_2)
{
  register s32 iVar1 asm("$t6");
  iVar1 = ((s32)param_2) >> 2;
  while (iVar1 = iVar1 + -1,iVar1 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  iVar1 = param_2 & 3;
  while (iVar1 = iVar1 + -1,iVar1 != -1) {
    *(u8 *)param_1 = 0;
    param_1 = (u32 *)((int)param_1 + 1);
  }
  return;
}
