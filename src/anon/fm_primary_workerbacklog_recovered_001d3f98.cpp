#include "../common/types.h"

asm(".globl SYM_01d6ba30
	SYM_01d6ba30 = 0x1d6ba30
");
asm(".globl SYM_0037e448
	SYM_0037e448 = 0x37e448
");
asm(".globl DAT_0034caf0
	DAT_0034caf0 = 0x34caf0
");
extern "C" char SYM_01d6ba30;
extern "C" char SYM_0037e448;
extern "C" volatile u32 DAT_0034caf0;
extern "C" void func_002fee78(u32,u32,u32,u32);

u32 func_001d3f98(u32 param_1)
{
  u32 uVar1;
  uVar1 = (u32)(long)&SYM_01d6ba30;
  func_002fee78(uVar1, (u32)(long)&SYM_0037e448, DAT_0034caf0, param_1 + 4);
  return uVar1;
}
