#include "../common/types.h"

// Preserve original registry aliases.
void func_001e7230(u32 *param_1,u32 param_2) asm("_Z16wtarget_001e7230jjjj");

void func_001e7230(u32 *param_1,u32 param_2)
{
  s32 iVar1;
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
