#include "../common/types.h"

/* 00143348 - v09. No barrier (v07) but the second result is read through an
 * inline barrier that only clobbers memory for the store pair, so GCC must keep
 * the load and the stores adjacent while still being free to hoist the
 * epilogue restore above them. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  *(u16 *)(param_1 + 280) = uVar1;
  asm volatile ("" ::: "memory");
  *(u16 *)(param_1 + 282) = (u16)uStack_20;
  return;
}
