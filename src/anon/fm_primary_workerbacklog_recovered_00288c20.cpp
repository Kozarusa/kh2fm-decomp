#include "../common/types.h"

asm(".globl DAT_0036f34c
	DAT_0036f34c = 0x36f34c
");

extern "C" u32 DAT_0036f34c;

typedef void (*code)(u32, u32);

void func_00288c20(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036f34c + 4))(DAT_0036f34c, param_1);
  }
}
