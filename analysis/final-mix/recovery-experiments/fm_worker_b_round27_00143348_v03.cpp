#include "../common/types.h"

/* 00143348 - v03. v02 fixed the global page and the store order; the only
 * residual is that GCC still emits both restores after the stores. v03 moves
 * the barrier to immediately after the call, before the two result reads, so
 * the ld ra,24(sp) is forced above the first sh. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  asm volatile ("" ::: "memory");
  u16 uVar2 = (u16)uStack_20;
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = uVar2;
  return;
}
