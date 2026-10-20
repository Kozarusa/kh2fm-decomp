#include "../common/types.h"

asm(".globl DAT_01d59508
	DAT_01d59508 = 0x1d59508
");

extern "C" u32 DAT_01d59508;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001c10f8(u32 param_1)
{
  u32 uVar1;
  uVar1 = DAT_01d59508;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x40, 0x320898);
  return;
}
