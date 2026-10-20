#include "../common/types.h"

asm(".globl DAT_0033b91c
	DAT_0033b91c = 0x33b91c
");
asm(".globl DAT_0033ba28
	DAT_0033ba28 = 0x33ba28
");
extern "C" char func_001037f8;
extern "C" u32 DAT_0033b91c;
extern "C" u8 DAT_0033ba28;
extern "C" void func_00102788(u32, u32, u32, u32);

void func_001037b8(void)
{
  func_00102788(DAT_0033b91c, 0, 0x5910, (u32)(long)&func_001037f8);
  DAT_0033ba28 = 1;
  return;
}
