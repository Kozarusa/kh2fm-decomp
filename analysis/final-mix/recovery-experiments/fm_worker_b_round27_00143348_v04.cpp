#include "../common/types.h"

/* 00143348 - v04. v03 has the right store order but GCC still emits both
 * restores after the stores. v04 adds a register barrier on the first stored
 * value as well as the memory barrier; the round-24 register barrier is the
 * other documented way to stop GCC from sinking an insn past a point. */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  asm volatile ("" : "+r"(uVar1));
  u16 uVar2 = (u16)uStack_20;
  asm volatile ("" ::: "memory");
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = uVar2;
  return;
}
