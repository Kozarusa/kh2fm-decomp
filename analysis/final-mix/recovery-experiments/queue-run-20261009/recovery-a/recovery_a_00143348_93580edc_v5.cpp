#include "../common/types.h"

/* 00143348 - v02. Two changes over v01, each measured:
 *   global: declaring 0x358800 measured lui 0x36, i.e. this compiler rounds
 *           (0x358800+0x8000)>>16 == 0x36, so 0x348800 is the declaration that
 *           yields the target's lui 0x35 with the same low half 0x8800;
 *   epilogue: the target restores ld ra,24(sp) before the first store and
 *           ld s0,16(sp) after the last; an empty memory barrier placed between
 *           the call result reads and the stores pins that split (round-23 lever). */

extern "C" u16 func_00147050(u32, u32, u32, u32, u32 *);
extern "C" u32 D_00348800;

void func_00143348(u32 param_1)
{
  u32 uStack_20 = 0;
  u16 uVar1 = func_00147050(D_00348800, 0, param_1, 0, &uStack_20);
  asm volatile ("" ::: "memory");
  u16 uVar2 = (u16)uStack_20;
  register u32 ra asm("$31"); asm volatile ("" : : "r"(ra));
  *(u16 *)(param_1 + 280) = uVar1;
  *(u16 *)(param_1 + 282) = uVar2;
  return;
}
