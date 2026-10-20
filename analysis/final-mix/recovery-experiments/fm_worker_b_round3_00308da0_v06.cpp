#include "../common/types.h"

void func_00308da0(char *param_1)
{
  u32 *puVar1 = (u32 *)param_1;
  *(u32 *)(param_1 + 0x18) = 0;
  puVar1[4] &= 0xfffffffeu;
}
