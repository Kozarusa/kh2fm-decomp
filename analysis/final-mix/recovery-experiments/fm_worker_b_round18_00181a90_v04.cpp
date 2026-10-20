#include "../common/types.h"

asm(".globl DAT_0033bb30
	DAT_0033bb30 = 0x33bb30
");
extern "C" u8 DAT_0033bb30;
extern "C" void func_00181178(u32);

void func_00181a90(void)
{
  func_00181178(18504);
  func_00181178(18505);
  DAT_0033bb30 = 18;
  *(u32 *)(long)(&DAT_0033bb30 + 13) = 18;
  DAT_0033bb30 = 99;
  *(u32 *)(long)(&DAT_0033bb30 + 12) = 18;
  return;
}
