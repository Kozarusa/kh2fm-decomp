#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_01d58cb0;
asm(".globl DAT_01d58cb0
	DAT_01d58cb0 = 0x1d58cb0
");
extern "C" void func_001b5460(u32);
extern "C" void func_001b4f40(u32);
extern "C" void func_00105110(u32);

void func_001b43e0(void)
{
  u32 uVar1;
  uVar1 = DAT_01d58cb0;
  if (uVar1 != 0) {
    func_001b5460(uVar1);
    uVar1 = DAT_01d58cb0;
    if (uVar1 != 0) {
      func_001b4f40(uVar1);
      func_00105110(uVar1);
    }
  }
  return;
}
