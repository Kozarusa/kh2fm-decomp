#include "../common/types.h"

/* 00143348 - v06. v02..v05 all leave both restores after the two stores. The
 * target pins `ld ra,24(sp)` between the final `lhu` and the first `sh`. v06
 * forces the epilogue load to be scheduled early by making the stack slot for
 * the callee's out-parameter volatile-read before the barrier and by pinning
 * the callee itself to an inout register operand, which was the round-24 lever
 * that moved a load. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  asm volatile ("" : "+r"(uVar1) : : "memory");
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = (u16)uStack_20;
  return;
}
