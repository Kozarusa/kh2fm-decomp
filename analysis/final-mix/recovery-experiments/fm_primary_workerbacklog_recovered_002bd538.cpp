#include "../common/types.h"

asm(".globl DAT_003617e4
	DAT_003617e4 = 0x3617e4
");

extern "C" u32 DAT_003617e4;

asm(".globl DAT_003617e0
	DAT_003617e0 = 0x3617e0
");

extern "C" u32 DAT_003617e0;

asm(".globl DAT_003617e8
	DAT_003617e8 = 0x3617e8
");

extern "C" u8 DAT_003617e8;
extern "C" u32 func_002b823c(void);

void func_002bd538(void)
{
  DAT_003617e4 = 0;
  DAT_003617e0 = func_002b823c();
  DAT_003617e8 = 1;
}
