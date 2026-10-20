#include "../common/types.h"

asm(".globl DAT_01dae340
	DAT_01dae340 = 0x1dae340
");

extern "C" u32 DAT_01dae340;

typedef void (*code)(u32, u32);

void func_001de978(u32 param_1)
{
  (*(code *)(*(u32 *)DAT_01dae340 + 4))(DAT_01dae340, param_1);
  asm volatile ("");
}
