#include "../common/types.h"

asm(".globl DAT_0036ebe0
	DAT_0036ebe0 = 0x36ebe0
");

extern "C" u32 DAT_0036ebe0;

typedef void (*code)(u32, u32);

void func_0023fb90(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036ebe0 + 4))(DAT_0036ebe0, param_1);
  }
}
