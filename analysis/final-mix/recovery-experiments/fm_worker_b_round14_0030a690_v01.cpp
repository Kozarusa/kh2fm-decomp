#include "../common/types.h"

asm(".globl DAT_00366164
	DAT_00366164 = 0x366164
");

extern "C" u32 DAT_00366164;

extern "C" void func_002fde18(u32, u32, u32);

u32 func_0030a690(void)
{
  DAT_00366164 = 0;
  func_002fde18(0x1e389a8, 0, 4);
  return 0;
}
