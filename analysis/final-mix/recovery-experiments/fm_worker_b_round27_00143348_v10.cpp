#include "../common/types.h"

/* 00143348 - v10. Every C-level shape so far leaves both epilogue restores after
 * the two stores, while the target has `ld ra,24(sp)` between the final `lhu`
 * and the first `sh`. v10 writes the two halfword stores as volatile inline
 * asm without a memory clobber: the operands pin the `lhu` early, but GCC is
 * still free to float the epilogue load above the asm statements. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  u16 uVar2 = (u16)uStack_20;
  asm volatile ("sh %0, 280(%1)" : : "r"(uVar1), "r"(param_1));
  asm volatile ("sh %0, 282(%1)" : : "r"(uVar2), "r"(param_1));
  return;
}
