#include "../common/types.h"

/* 00143348 - v12. v10/v11 reached the right store order and the right place for
 * the final `lhu`, leaving only `ld ra,24(sp)` misplaced. v12 reverts to plain
 * C stores and puts the memory barrier between them, which is the one shape that
 * made GCC hoist the epilogue restore at all (v05, v09), while the second result
 * is read through a u16 pointer so the `lhu` cannot be sunk past the barrier. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  *(u16 *)(param_1 + 280) = uVar1;
  asm volatile ("" ::: "memory");
  *(u16 *)(param_1 + 282) = *(u16 *)&uStack_20;
  return;
}
