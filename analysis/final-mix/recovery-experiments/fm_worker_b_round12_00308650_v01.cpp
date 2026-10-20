#include "../common/types.h"

asm(".globl DAT_003660d8
	DAT_003660d8 = 0x3660d8
");

extern "C" u32 DAT_003660d8;
asm(".globl DAT_01e87d4
	DAT_01e87d4 = 0x1e87d4
");

extern "C" u32 DAT_01e87d4;

extern "C" void func_003061d0(u32);
extern "C" void func_00305350(u32, u32);

void func_00308650(void)
{
  u32 iVar1;
  func_003061d0(5);
  iVar1 = *(u32 *)DAT_01e87d4;
  func_00305350(5, iVar1);
  DAT_003660d8 = iVar1;
}
