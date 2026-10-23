#include "../common/types.h"

asm(".globl DAT_00352768
	DAT_00352768 = 0x352768
");

extern "C" u32 DAT_00352768;

asm(".globl DAT_01d6ba68
	DAT_01d6ba68 = 0x1d6ba68
");

extern "C" u32 DAT_01d6ba68;

extern "C" u32 func_00168b38(u32, u32, u32);

void func_001d5030(u32 param_1)
{
  u32 iVar1;
  DAT_00352768 = param_1;
  iVar1 = func_00168b38(param_1, 2, 0);
  DAT_01d6ba68 = *(u32 *)(iVar1 + 8);
}
