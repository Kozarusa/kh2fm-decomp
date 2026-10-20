#include "../common/types.h"

asm(".globl DAT_01d58d90
	DAT_01d58d90 = 0x1d58d90
");

extern "C" u32 DAT_01d58d90;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001b8800(u32 param_1)
{
  u32 uVar1;
  asm volatile ("" ::: "memory");
  uVar1 = DAT_01d58d90;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, 0x320448);
  asm volatile ("");
  return;
}
