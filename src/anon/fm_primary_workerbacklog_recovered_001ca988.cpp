#include "../common/types.h"

extern "C" void func_001c6fa8(u32, u32);

void func_001ca988(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6)
{
  func_001c6fa8(param_1, param_2);
  *(u32 *)(param_1 + 0x54) = param_6;
  *(u32 *)(param_1 + 0x58) = 0;
  return;
}
