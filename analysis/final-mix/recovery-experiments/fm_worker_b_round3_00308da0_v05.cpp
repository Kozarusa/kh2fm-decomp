#include "../common/types.h"

void func_00308da0(u32 *param_1)
{
  u32 uVar1;
  uVar1 = 0xfffffffe;
  *(u32 *)((char *)param_1 + 0x18) = 0;
  param_1[4] &= uVar1;
}
