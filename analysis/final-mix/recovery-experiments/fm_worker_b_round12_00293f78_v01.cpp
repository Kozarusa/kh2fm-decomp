#include "../common/types.h"

asm(".globl DAT_0036f570
	DAT_0036f570 = 0x36f570
");

extern "C" u32 DAT_0036f570;

typedef void (*code)(u32, u32);

void func_00293f78(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036f570 + 4))(DAT_0036f570, param_1);
  }
}
