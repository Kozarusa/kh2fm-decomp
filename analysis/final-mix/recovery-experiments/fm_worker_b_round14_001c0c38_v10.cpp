#include "../common/types.h"

asm(".globl DAT_01d59360
	DAT_01d59360 = 0x1d59360
");

extern "C" u32 DAT_01d59360;

/* Declaring the 5th argument's absolute symbol and passing ITS ADDRESS makes GCC
   materialise it through the relocation path (lui %hi / addiu %lo) instead of
   li_operand (lui / ori), which is what the original build did. */
extern "C" char func_00320888;

extern "C" void func_002fd248(u32, u32, u32, u32, u32);

void func_001c0c38(u32 param_1)
{
  u32 uVar1;
  asm volatile ("" ::: "memory");
  uVar1 = DAT_01d59360;
  func_002fd248(param_1, uVar1 + 8, *(u32 *)(uVar1 + 4), 0x20, (u32)(long)&func_00320888);
  asm volatile ("");
  return;
}
