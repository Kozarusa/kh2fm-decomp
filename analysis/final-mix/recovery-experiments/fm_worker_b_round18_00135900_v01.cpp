#include "../common/types.h"

asm(".globl PTR_00347d00
	PTR_00347d00 = 0x347d00
");
asm(".globl DAT_00347cf0
	DAT_00347cf0 = 0x347cf0
");
extern "C" u32 PTR_00347d00;
extern "C" u32 DAT_00347cf0;
extern "C" void func_00135aa0(u32);

void func_00135900(u32 param_1)
{
  u32 uVar1;
  *(u32 *)param_1 = (u32)(long)&PTR_00347d00;
  func_00135aa0(param_1);
  uVar1 = DAT_00347cf0;
  *(u32 *)(param_1 + 8) = uVar1;
  DAT_00347cf0 = param_1;
  asm volatile ("");
  return;
}
