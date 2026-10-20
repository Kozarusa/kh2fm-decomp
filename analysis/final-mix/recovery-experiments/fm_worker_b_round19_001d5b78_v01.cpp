#include "../common/types.h"

asm(".globl DAT_01d6ba60
	DAT_01d6ba60 = 0x1d6ba60
");
extern "C" u32 *DAT_01d6ba60;
extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001d5b78(u32 param_1, u32 param_2)
{
  u32 *puVar1 = DAT_01d6ba60;
  func_002fd248(param_1 << 4 | param_2, (u32)(long)(puVar1 + 2), *(u32 *)((u32 *)puVar1 + 1), 8, 0x3217a0);
  return;
}
