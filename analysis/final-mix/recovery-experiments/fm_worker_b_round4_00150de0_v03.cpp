#include "../common/types.h"

extern "C" void func_00150e00(void);

void func_00150de0(u32 param_1)
{
  register u32 uVar1 asm("$t1") = 0xffffffffu;
  *(u32 *)(param_1 + 0x19a0) = uVar1;
  func_00150e00();
}
