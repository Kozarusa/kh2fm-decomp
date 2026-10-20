#include "../common/types.h"

/* 00143348 - v07. The residual is purely where GCC puts `ld ra,24(sp)`: the
 * target has it between the final `lhu` and the first `sh`, GCC has it after
 * both stores. A memory barrier forbids the load from crossing the stores, so
 * v07 drops the barrier entirely and lets GCC float the epilogue load up. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = (u16)uStack_20;
  return;
}
