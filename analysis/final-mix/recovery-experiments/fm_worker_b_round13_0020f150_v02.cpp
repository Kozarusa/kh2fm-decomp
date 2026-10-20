#include "../common/types.h"

asm(".globl DAT_003691c8
	DAT_003691c8 = 0x3691c8
");

extern "C" u32 DAT_003691c8;

extern "C" void func_002f25a0(u32, u32);
extern "C" void func_002f3918(u32, u32);

void func_0020f150(void)
{
  func_002f25a0(0, 0);
  func_002f3918(DAT_003691c8, 0x359910);
  asm volatile ("");
}
