#include "../common/types.h"

asm(".globl DAT_0036f5d0
	DAT_0036f5d0 = 0x36f5d0
");
extern "C" u32 DAT_0036f5d0;
extern "C" u32 func_00276c18(void);

u32 func_002a0360(void)
{
  u32 uVar1;
  u32 uVar2;
  uVar2 = (*(s8 *)(long)DAT_0036f5d0 > 0);
  asm volatile ("");
  uVar1 = func_00276c18();
  return uVar2 != 0 ? 1 : uVar1;
}
