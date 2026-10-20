#include "../common/types.h"

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 param_1)
{
  *(u32 *)(param_1 + 0x70) = 4u;
  func_001991a8(34u,*(u32 *)(param_1 + 0x80));
}
