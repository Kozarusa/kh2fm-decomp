#include "../common/types.h"

asm(".globl PTR_00350330
	PTR_00350330 = 0x350330
"
    ".globl DAT_01c61b00
	DAT_01c61b00 = 0x1c61b00
");

extern "C" u32 PTR_00350330;
extern "C" u32 DAT_01c61b00;
extern "C" u32 func_001b1448(u32);

void func_00196170(void)
{
  DAT_01c61b00 = func_001b1448(PTR_00350330);
}
