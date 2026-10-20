#include "../common/types.h"

asm(".globl DAT_01d5ba9c
	DAT_01d5ba9c = 0x1d5ba9c
");

extern "C" u32 DAT_01d5ba9c;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001d7980(u32 param_1)
{
  u32 uVar1;
  uVar1 = DAT_01d5ba9c;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 4, 0x3218b8);
  return;
}
