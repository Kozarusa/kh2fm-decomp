#include "../common/types.h"

asm(".globl DAT_0033bb1c
	DAT_0033bb1c = 0x33bb1c
");

extern "C" volatile u32 DAT_0033bb1c;
extern "C" void func_00109280(u32);
extern "C" void func_00170c00(u32);
extern "C" void func_00170320(u32);

void func_001053c0(void)
{
  func_00109280(DAT_0033bb1c);
  func_00170c00(DAT_0033bb1c);
  func_00170320(0);
  DAT_0033bb1c = 0;
  return;
}
