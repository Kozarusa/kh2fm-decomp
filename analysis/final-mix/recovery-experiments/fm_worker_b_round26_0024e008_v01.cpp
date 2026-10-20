#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_0035f264;
asm(".globl DAT_0035f264
	DAT_0035f264 = 0x35f264
");
extern "C" void func_0024dfe0(u32);

u32 func_0024e008(u32 param_1)
{
  u32 uVar1;
  func_0024dfe0(param_1);
  uVar1 = param_1 * 6;
  if (DAT_0035f264 == 0) {
    uVar1 = uVar1 + 0x372178;
  }
  else {
    uVar1 = uVar1 + 0x372160;
  }
  return uVar1;
}
