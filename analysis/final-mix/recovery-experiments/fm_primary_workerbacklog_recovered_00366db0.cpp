#include "../common/types.h"

extern "C" void func_00076160(u32);

void func_00366db0(u16 param_1)
{
  func_00076160(param_1);
  asm volatile("sync");
}
