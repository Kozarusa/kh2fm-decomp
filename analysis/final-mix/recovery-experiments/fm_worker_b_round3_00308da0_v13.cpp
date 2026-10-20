#include "../common/types.h"

u32 func_00308da0(u32 *param_1)
{
  *(u32 *)((char *)param_1 + 0x18) = 0;
  param_1[4] &= 0xfffffffeu;
  return param_1[4];
}
