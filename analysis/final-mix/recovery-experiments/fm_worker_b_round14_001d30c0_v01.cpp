#include "../common/types.h"

asm(".globl DAT_01d5ba0c
	DAT_01d5ba0c = 0x1d5ba0c
");

extern "C" u32 DAT_01d5ba0c;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001d30c0(u32 param_1)
{
  u32 uVar1;
  uVar1 = DAT_01d5ba0c;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 8, 0x3216a8);
  return;
}
