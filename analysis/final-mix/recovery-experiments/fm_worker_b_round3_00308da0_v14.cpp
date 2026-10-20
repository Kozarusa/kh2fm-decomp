#include "../common/types.h"

long long func_00308da0(u32 *param_1)
{
  *(u32 *)((char *)param_1 + 0x18) = 0;
  param_1[4] &= 0xfffffffe;
  return param_1[4];
}
