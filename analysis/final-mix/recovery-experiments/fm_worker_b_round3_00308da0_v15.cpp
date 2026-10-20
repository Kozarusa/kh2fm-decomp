#include "../common/types.h"

void func_00308da0(u32 *param_1)
{
  long lVar1;
  *(u32 *)((char *)param_1 + 0x18) = 0;
  lVar1 = param_1[4] & 0xfffffffeL;
  param_1[4] = (u32)lVar1;
}
