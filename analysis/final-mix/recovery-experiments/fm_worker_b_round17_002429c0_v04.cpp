#include "../common/types.h"

extern "C" u32 func_001058e8(void);

void func_002429c0(u32 param_1, u32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  uVar2 = param_2;
  uVar3 = param_1;
  uVar1 = func_001058e8();
  asm volatile ("");
  uVar2 = uVar1 + 16800;
  *(u16 *)(uVar2 + 16800) = (u16)uVar3;
  *(u16 *)(uVar2 + 2) = (u16)uVar2;
  return;
}
