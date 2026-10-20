#include "../common/types.h"

extern "C" void func_001c6fa8(void, u32);

void func_001ca950(u32 param_1)
{
  u32 uVar1;
  uVar1 = param_1;
  func_001c6fa8();
  *(u32 *)(uVar1 + 0x54) = 0;
  *(u32 *)(uVar1 + 0x58) = 0;
  return;
}
