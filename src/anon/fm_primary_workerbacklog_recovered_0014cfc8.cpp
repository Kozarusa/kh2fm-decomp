#include "../common/types.h"

asm(".globl DAT_00359e04
	DAT_00359e04 = 0x359e04
");

asm(".globl DAT_00359e08
	DAT_00359e08 = 0x359e08
");

extern "C" volatile u32 DAT_00359e04;
extern "C" volatile u32 DAT_00359e08;
extern "C" void func_0014ce20(u32);
extern "C" void func_0014ce30(u32);
extern "C" void func_0014ce60(void);

void func_0014cfc8(void)
{
  func_0014ce20(1);
  func_0014ce30(1);
  func_0014ce60();
  DAT_00359e04 = 0;
  DAT_00359e08 = 0;
  return;
}
