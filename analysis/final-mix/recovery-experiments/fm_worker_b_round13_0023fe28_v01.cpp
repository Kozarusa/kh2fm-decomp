#include "../common/types.h"

asm(".globl DAT_0036ec84
	DAT_0036ec84 = 0x36ec84
");

extern "C" u32 DAT_0036ec84;

typedef void (*code)(u32, u32);

void func_0023fe28(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036ec84 + 4))(DAT_0036ec84, param_1);
  }
}
