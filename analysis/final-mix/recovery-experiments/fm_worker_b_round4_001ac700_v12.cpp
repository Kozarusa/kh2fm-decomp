#include "../common/types.h"

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 param_1)
{
  *(u32 *)(param_1 + 0x70) = 4;
  func_001991a8(0x22,*(volatile u32 *)(param_1 + 0x80));
}
