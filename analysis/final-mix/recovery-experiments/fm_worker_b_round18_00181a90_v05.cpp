#include "../common/types.h"

asm(".globl DAT_0033bb30
	DAT_0033bb30 = 0x33bb30
");
extern "C" u8 DAT_0033bb30;
extern "C" void func_00181178(u32);

void func_00181a90(void)
{
  u8 *puVar1;
  func_00181178(18504);
  func_00181178(18505);
  puVar1 = (u8 *)(long)&DAT_0033bb30;
  *(volatile u8 *)(puVar1 + 13) = 18;
  *(volatile u8 *)(puVar1 + 14) = 99;
  *(volatile u8 *)(puVar1 + 12) = 18;
  return;
}
