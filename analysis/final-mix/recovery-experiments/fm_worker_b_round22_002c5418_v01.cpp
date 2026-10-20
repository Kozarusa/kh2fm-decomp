#include "../common/types.h"

extern "C" u32 func_00102788(u32,u32,u32,u32);
extern "C" u32 DAT_0033b96c;
asm(".globl DAT_0033b96c
	DAT_0033b96c = 0x33b96c
");

extern "C" char func_002c53c8;

void func_002c5418(u32 param_1)
{
  u32 iVar1;
  iVar1 = func_00102788(DAT_0033b96c, 0, 300000, (u32)(long)&func_002c53c8);
  *(u32 *)(iVar1 + 4) = param_1;
  return;
}
