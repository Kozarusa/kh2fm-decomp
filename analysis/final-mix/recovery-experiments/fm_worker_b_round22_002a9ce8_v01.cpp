#include "../common/types.h"

extern "C" volatile u32 DAT_0036f610;
asm(".globl DAT_0036f610
	DAT_0036f610 = 0x36f610
");
extern "C" u32 func_00103570(void);
extern "C" u32 func_001063c0(u32);
extern "C" void func_00319a60(u32);

void func_002a9ce8(void)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = func_00103570();
  uVar2 = func_001063c0(2408);
  func_00319a60(uVar2);
  DAT_0036f610 = uVar2;
  return;
}
