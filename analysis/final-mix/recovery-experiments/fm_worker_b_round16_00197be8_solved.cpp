#include "../common/types.h"

asm(".globl DAT_0035037c
	DAT_0035037c = 0x35037c
");

extern "C" u32 DAT_0035037c;
extern "C" void func_00196e00(u32);
extern "C" void func_00105110(u32);

void func_00197be8(void)
{
  u32 uVar1;
  uVar1 = DAT_0035037c;
  if (uVar1 != 0) {
    func_00196e00(uVar1);
    func_00105110(uVar1);
    asm volatile ("");
  }
  return;
}
