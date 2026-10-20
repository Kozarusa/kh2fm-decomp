#include "../common/types.h"

asm(".globl DAT_00361f60
	DAT_00361f60 = 0x361f60
");

extern "C" u32 DAT_00361f60;
extern "C" void func_002ceb08(void);

u32 func_002e2e18(void)
{
  u32 uVar1;
  u32 uVar2;
  uVar2 = 0;
  uVar1 = DAT_00361f60;
  if (uVar1 != 0) {
    func_002ceb08();
    uVar2 = *(u32 *)(uVar1 + 0x108);
  }
  return uVar2;
}
