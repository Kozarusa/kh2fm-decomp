#include "../common/types.h"

extern "C" void func_00305650(...);

u64 func_003068d8(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  func_00305650(param_4);
  asm volatile ("sync");
  asm volatile ("ei");
  return 0;
}
