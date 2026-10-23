#include "../common/types.h"

asm(".globl PTR_00350334
	PTR_00350334 = 0x350334
"
    ".globl DAT_01c61b04
	DAT_01c61b04 = 0x1c61b04
");

extern "C" u32 PTR_00350334;
extern "C" u32 DAT_01c61b04;
extern "C" u32 func_001b1448(u32);

void func_00196300(void)
{
  DAT_01c61b04 = func_001b1448(PTR_00350334);
}
