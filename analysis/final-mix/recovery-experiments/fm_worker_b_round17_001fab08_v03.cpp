#include "../common/types.h"

extern "C" void func_0021fa10(u32);

void func_001fab08(u32 param_1, u32 *param_2)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = *(u32 *)(param_2 + 3);
  uVar2 = *(u32 *)(long)uVar1;
  asm volatile ("" : "+r"(uVar1));
  uVar2 = param_1 + uVar2;
  uVar2 = uVar2 + 160;
  func_0021fa10(uVar2);
  *(volatile u8 *)(uVar2 + 8) = 4;
  return;
}
