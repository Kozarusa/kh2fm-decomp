#include "../common/types.h"

asm(".globl DAT_01d5ba0c
	DAT_01d5ba0c = 0x1d5ba0c
");

extern "C" u32 DAT_01d5ba0c;

/* Declaring the 5th argument's absolute symbol and passing ITS ADDRESS makes GCC
   materialise it through the relocation path (lui %hi / addiu %lo) instead of
   li_operand (lui / ori), which is what the original build did. */
extern "C" char func_003216a8;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001d30c0(u32 param_1)
{
  u32 uVar1;
  asm volatile ("" ::: "memory");
  uVar1 = DAT_01d5ba0c;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 8, (u32)(long)&func_003216a8);
  asm volatile ("");
  return;
}
