#include "../common/types.h"

asm(".globl DAT_01d59360
	DAT_01d59360 = 0x1d59360
");

extern "C" u32 DAT_01d59360;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001c0c38(u32 param_1)
{
  u32 uVar1;
  uVar1 = DAT_01d59360;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x20, 0x320888);
  return;
}
