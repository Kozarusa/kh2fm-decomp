#include "../common/types.h"

static const u32 mask_00308da0 = 0xfffffffe;

void func_00308da0(u32 *param_1)
{
  *(u32 *)((char *)param_1 + 0x18) = 0;
  param_1[4] &= mask_00308da0;
}
