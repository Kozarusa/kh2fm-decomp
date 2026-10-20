#include "../common/types.h"

asm(".globl PTR_003528fc
	PTR_003528fc = 0x3528fc
"
    ".globl DAT_01d6baa8
	DAT_01d6baa8 = 0x1d6baa8
");

extern "C" u32 PTR_003528fc;
extern "C" u32 DAT_01d6baa8;
extern "C" u32 func_001b1448(u32);

void func_001d9d00(void)
{
  DAT_01d6baa8 = func_001b1448(PTR_003528fc);
}
