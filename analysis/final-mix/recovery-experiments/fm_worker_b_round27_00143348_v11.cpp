#include "../common/types.h"

/* 00143348 - v11. As v10 but the stores keep a memory clobber, so the `lhu`
 * must complete before the first store while the epilogue load is a scheduling
 * boundary the barrier cannot move. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  u16 uVar2 = (u16)uStack_20;
  asm volatile ("sh %0, 280(%1)" : : "r"(uVar1), "r"(param_1) : "memory");
  asm volatile ("sh %0, 282(%1)" : : "r"(uVar2), "r"(param_1) : "memory");
  return;
}
