#include "../common/types.h"

asm(".globl DAT_0036f654
	DAT_0036f654 = 0x36f654
");
asm(".globl DAT_0036f650
	DAT_0036f650 = 0x36f650
");
extern "C" volatile u32 DAT_0036f654;
extern "C" volatile u32 DAT_0036f650;
extern "C" u64 func_00139d78(u32);
extern "C" void func_0028acc8(u32);

void func_002b4fb8(void)
{
  u32 uVar1;
  u64 uVar2;
  uVar2 = 0;
  uVar1 = DAT_0036f654;
  if (uVar1 != 0) {
    uVar2 = func_00139d78(uVar1);
    if (uVar2 != 0) {
      func_0028acc8(DAT_0036f650);
    }
  }
  asm volatile ("");
  return;
}
