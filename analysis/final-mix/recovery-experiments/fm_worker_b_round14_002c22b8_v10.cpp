#include "../common/types.h"

asm(".globl DAT_01e3bd00
	DAT_01e3bd00 = 0x1e3bd00
");

extern "C" u32 DAT_01e3bd00;

/* Declaring the 5th argument's absolute symbol and passing ITS ADDRESS makes GCC
   materialise it through the relocation path (lui %hi / addiu %lo) instead of
   li_operand (lui / ori), which is what the original build did. */
extern "C" char func_00324bb0;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_002c22b8(u32 param_1)
{
  u32 uVar1;
  asm volatile ("" ::: "memory");
  uVar1 = DAT_01e3bd00;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x10, (u32)(long)&func_00324bb0);
  asm volatile ("");
  return;
}
