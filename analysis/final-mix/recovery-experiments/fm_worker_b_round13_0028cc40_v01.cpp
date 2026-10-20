#include "../common/types.h"

asm(".globl DAT_0036f3f8
	DAT_0036f3f8 = 0x36f3f8
");

extern "C" u32 DAT_0036f3f8;

typedef void (*code)(u32, u32);

void func_0028cc40(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036f3f8 + 4))(DAT_0036f3f8, param_1);
  }
}
