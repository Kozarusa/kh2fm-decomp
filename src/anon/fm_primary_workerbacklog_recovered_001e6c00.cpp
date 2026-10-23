#include "../common/types.h"

asm(".globl DAT_001de6e4
	DAT_001de6e4 = 0x1dae6e4
");

extern "C" u32 DAT_001de6e4;
extern "C" void func_002fde18(u32, u32, u32);
extern "C" void func_001e7798(u32, u32);

void func_001e6c00(u32 param_1)
{
  func_002fde18(param_1, 171, 336);
  func_001e7798(DAT_001de6e4, param_1);
  asm volatile ("");
  return;
}
