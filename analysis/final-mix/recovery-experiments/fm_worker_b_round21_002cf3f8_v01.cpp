#include "../common/types.h"

asm(".globl PTR_00361f94
	PTR_00361f94 = 0x361f94
");
extern "C" volatile u32 PTR_00361f94;
asm(".globl PTR_00361f90
	PTR_00361f90 = 0x361f90
");
extern "C" volatile u32 PTR_00361f90;
extern "C" u32 func_00106450(u32);

void func_002cf3f8(void)
{
  u32 uVar1;
  uVar1 = PTR_00361f94;
  if (uVar1 != 0) { func_00106450(uVar1); }
  PTR_00361f94 = 0;
  PTR_00361f90 = 0;
  return;
}
