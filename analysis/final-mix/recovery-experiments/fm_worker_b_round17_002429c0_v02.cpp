#include "../common/types.h"

extern "C" u32 func_001058e8(void);

void func_002429c0(u32 param_1, u32 param_2)
{
  u32 uVar1;
  uVar1 = func_001058e8();
  asm volatile ("");
  *(u16 *)uVar1 = (u16)param_1;
  *(u16 *)(uVar1 + 2) = (u16)param_2;
  return;
}
