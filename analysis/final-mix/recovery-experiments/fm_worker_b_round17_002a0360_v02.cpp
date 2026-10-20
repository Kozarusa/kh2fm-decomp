#include "../common/types.h"

asm(".globl DAT_0036f5d0
	DAT_0036f5d0 = 0x36f5d0
");
extern "C" u32 DAT_0036f5d0;
extern "C" u32 func_00276c18(void);

u32 func_002a0360(void)
{
  s8 *puVar1;
  u32 uVar1;
  u32 uVar2;
  puVar1 = (s8 *)(long)DAT_0036f5d0;
  uVar1 = func_00276c18();
  uVar2 = (*puVar1 > 0);
  return uVar2 ? 1 : uVar1;
}
