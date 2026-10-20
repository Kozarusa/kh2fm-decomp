#include "../common/types.h"

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 param_1)
{
  register u32 *puVar1 asm("$t6");
  puVar1 = (u32 *)param_1;
  puVar1[0x1c] = 4;
  func_001991a8(0x22,puVar1[0x20]);
}
