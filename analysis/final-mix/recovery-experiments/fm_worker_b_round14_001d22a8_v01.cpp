#include "../common/types.h"

asm(".globl DAT_01d5ba00
	DAT_01d5ba00 = 0x1d5ba00
");

extern "C" u32 DAT_01d5ba00;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001d22a8(u32 param_1)
{
  u32 uVar1;
  uVar1 = DAT_01d5ba00;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, 0x321688);
  return;
}
