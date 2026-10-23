#include "../common/types.h"

asm(".globl DAT_0036f334
	DAT_0036f334 = 0x36f334
");

extern "C" u32 DAT_0036f334;
extern "C" u64 func_002537c8(s32);
extern "C" void func_0023fa08(u32,u64);

void func_00288610(void)
{
  u64 uVar1;
  uVar1 = func_002537c8(0);
  func_0023fa08(DAT_0036f334,uVar1);
}
