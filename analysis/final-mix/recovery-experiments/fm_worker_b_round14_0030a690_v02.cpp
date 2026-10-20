#include "../common/types.h"

asm(".globl DAT_00366164
	DAT_00366164 = 0x366164
");

extern "C" u32 DAT_00366164;
extern "C" char func_01e389a8;
extern "C" char func_00366164;

extern "C" void func_002fde18(u32, u32, u32);

u32 func_0030a690(void)
{
  DAT_00366164 = 0;
  func_002fde18((u32)(long)&func_01e389a8, 0, 4);
  asm volatile ("");
  return 0;
}
