#include "../common/types.h"

asm(".globl DAT_00366180
	DAT_00366180 = 0x366180
");

extern "C" u32 DAT_00366180;
extern "C" char func_01d8e68;
extern "C" void func_002fde18(u32, u32, u32);

u32 func_0030df00(void)
{
  DAT_00366180 = 0xffffffff;
  func_002fde18((u32)(long)&func_01d8e68, 0, 4);
  return 0;
}
