#include "../common/types.h"

extern "C" void func_001e7798(u32,u32);
extern "C" u32 DAT_01d9e6e4;
asm(".globl DAT_01d9e6e4
	DAT_01d9e6e4 = 0x1d9e6e4
");

void func_001ea928(u32 param_1, u32 param_2)
{
  u32 iVar1;
  param_1 = param_1 + **(u32 **)(param_2 + 0xc);
  iVar1 = *(u32 *)(param_1 + 0xac);
  if (iVar1 != 0) {
    func_001e7798(DAT_01d9e6e4, iVar1);
    *(u32 *)(param_1 + 0xac) = 0;
  }
  return;
}
