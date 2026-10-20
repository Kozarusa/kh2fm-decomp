#include "../common/types.h"

extern "C" void func_001991a8(u32,u32);

void func_001ac700(u32 *param_1)
{
  param_1[0x1c] = 4;
  asm("" : "+r"(param_1));
  func_001991a8(0x22,param_1[0x20]);
}
