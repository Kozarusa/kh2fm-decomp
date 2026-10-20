#include "../common/types.h"

/* 00143348 - v05. Same goal as v04 from the other end: keep the two result
 * reads adjacent to the call (as in v01, which already had the right store
 * order) and place the memory barrier between the two stores instead of before
 * them, so the ld ra has one store to be hoisted across. */

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
