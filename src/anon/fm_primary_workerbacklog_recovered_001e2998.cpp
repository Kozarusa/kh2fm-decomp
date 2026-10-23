#include "../common/types.h"

extern "C" void func_001e2898(u32);
extern "C" void func_00105110(u32);
extern "C" volatile u32 DAT_00352bd0;
asm(".globl DAT_00352bd0
	DAT_00352bd0 = 0x352bd0
");

void func_001e2998(void)
{
  u32 iVar1;
  iVar1 = DAT_00352bd0;
  if (iVar1 != 0) {
    func_001e2898(iVar1);
    func_00105110(iVar1);
  }
  DAT_00352bd0 = 0;
  return;
}
