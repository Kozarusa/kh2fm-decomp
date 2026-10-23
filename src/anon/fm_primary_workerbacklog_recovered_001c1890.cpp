#include "../common/types.h"

extern "C" void func_003208a8(u32, u32);
extern "C" void func_001db8b8(u32, u32);

void func_001c1890(volatile u32 *param_1)
{
  func_003208a8(*(u32 *)(param_1 + 7) + 12, (u32)param_1);
  func_001db8b8(*(u32 *)(param_1 + 7) + 20, (u32)param_1);
  asm volatile ("");
  return;
}
