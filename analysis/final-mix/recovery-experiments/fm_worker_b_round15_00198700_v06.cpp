#include "../common/types.h"

extern "C" u32 func_001b9bc8(u32);

void func_00198700(u32 param_1)
{
  asm volatile ("" ::: "memory");
  do {
    param_1 = func_001b9bc8(param_1);
    if (param_1 == 0) {
      return;
    }
  } while (((*(u32 *)(param_1 + 0x588) & 1) & 0xff) == 0);
  return;
}
