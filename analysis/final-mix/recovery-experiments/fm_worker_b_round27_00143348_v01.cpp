#include "../common/types.h"

/* 00143348 - v01
 * lui t7,0x35 ; lw a0,-30720(t7) => effective address 0x350000-30720 = 0x348800.
 * Declared as 0x358800 so the truncating lui reproduces 0x35 (round-6 rule). */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00358800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00358800, 0, param_1, 0, &uStack_20);
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = (u16)uStack_20;
  return;
}
