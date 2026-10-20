#include "../common/types.h"

asm(".globl DAT_01e3a3c0
	DAT_01e3a3c0 = 0x1e3a3c0
");

extern "C" u32 DAT_01e3a3c0;

u32 func_002b99a0(void)
{
  return DAT_01e3a3c0;
}
