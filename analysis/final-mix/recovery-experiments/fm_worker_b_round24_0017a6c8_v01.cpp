#include "../common/types.h"

extern "C" u32 func_0019ba60(void);
extern "C" volatile u32 DAT_0035e948;
asm(".globl DAT_0035e948
	DAT_0035e948 = 0x35e948
");

u32 func_0017a6c8(void)
{
  u32 *puVar1;
  s32 iVar1;
  iVar1 = 0;
  if (func_0019ba60() != 0) {
    puVar1 = (u32 *)DAT_0035e948;
    iVar1 = (puVar1[88] & 0x4000) != 0;
  }
  return iVar1;
}
