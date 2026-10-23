#include "../common/types.h"

asm(".globl DAT_0036ebe0
	DAT_0036ebe0 = 0x36ebe0
"
    ".globl DAT_0036ebec
	DAT_0036ebec = 0x36ebec
");

extern "C" u32 DAT_0036ebe0;
extern "C" u32 DAT_0036ebec;
extern "C" void func_0023fbc8();

void func_0023fb00(u32 param_1)
{
  DAT_0036ebe0 = param_1;
  func_0023fbc8();
  DAT_0036ebec = 0;
}
