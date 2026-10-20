#include "../common/types.h"

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 param_1)
{
  u32 *puVar1;
  puVar1 = (u32 *)param_1;
  func_001991a8(0x22,puVar1[0x20]);
  puVar1[0x1c] = 4;
}
