#include "../common/types.h"

extern "C" u64 func_001d7f10(void);
extern "C" u32 DAT_003528f8;
asm(".globl DAT_003528f8
	DAT_003528f8 = 0x3528f8
");

s32 func_001d7ec8(u32 param_1)
{
  u64 uVar1;
  u32 *puVar1;
  s32 iVar1;
  iVar1 = 0;
  uVar1 = func_001d7f10();
  puVar1 = (u32 *)((u32)DAT_003528f8 + param_1 * 4);
  if (uVar1 != 0) {
    iVar1 = *(s32 *)(puVar1 + 2);
  }
  return iVar1;
}
