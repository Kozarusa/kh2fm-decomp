#include "../common/types.h"

/* 00143348 - v08. Same as v07 but the callee's out-parameter slot is volatile,
 * which pins the final `lhu t7,0(sp)` to its position right before the second
 * store so the two loads cannot both be hoisted into the argument setup. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  volatile u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, (u32 *)&uStack_20);
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = (u16)uStack_20;
  return;
}
