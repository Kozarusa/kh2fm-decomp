#include "../common/types.h"

void func_001e7230(u32 *param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  iVar1 = (int)param_2 >> 2;
  while (iVar1 = iVar1 + -1, iVar1 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  iVar2 = (int)param_2 & 3;
  while (iVar2 = iVar2 - 1, iVar2 != 0xffffffff) {
    *(u8 *)param_1 = 0;
    param_1 = (u32 *)((int)param_1 + 1);
  }
  return;
}
