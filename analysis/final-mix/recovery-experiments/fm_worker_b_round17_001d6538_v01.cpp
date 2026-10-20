#include "../common/types.h"

asm(".globl PTR_001d5ba78
	PTR_001d5ba78 = 0x1d5ba78
");
asm(".globl PTR_00352780
	PTR_00352780 = 0x352780
");
extern "C" void func_001ce378(u32);

void func_001d6538(u32 param_1)
{
  func_001ce378(param_1);
  *(u32 *)(param_1 + 0x9f8) = (u32)(long)&PTR_001d5ba78;
  *(u32 *)param_1 = (u32)(long)&PTR_00352780;
  return;
}
