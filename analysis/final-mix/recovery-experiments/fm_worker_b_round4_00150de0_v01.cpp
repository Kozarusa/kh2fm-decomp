#include "../common/types.h"

extern "C" void func_00150e00(void);

void func_00150de0(u32 param_1)
{
  *(u32 *)(param_1 + 0x19a0) = 0xffffffff;
  func_00150e00();
}
