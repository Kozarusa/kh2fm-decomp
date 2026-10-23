#include "../common/types.h"

asm(".globl DAT_0036ecbc
	DAT_0036ecbc = 0x36ecbc
");

extern "C" u32 DAT_0036ecbc;

typedef void (*code)(u32, u32);

void func_00242368(u32 param_1)
{
  if (param_1 != 0) {
    (*(code *)(*(u32 *)DAT_0036ecbc + 4))(DAT_0036ecbc, param_1);
  }
}
