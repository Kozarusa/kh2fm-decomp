#include "../common/types.h"

// Preserve original registry aliases.
void func_002cf3f8(void) asm("_Z16ctarget_002cf3f8jjjj");

asm(".globl PTR_00361fa4
	PTR_00361fa4 = 0x361fa4
");
asm(".globl PTR_00361fa0
	PTR_00361fa0 = 0x361fa0
");
extern "C" volatile u32 PTR_00361fa4;
extern "C" volatile u32 PTR_00361fa0;
extern "C" u32 func_00106450(u32);

void func_002cf3f8(void)
{
  u32 uVar1;
  uVar1 = PTR_00361fa4;
  if (uVar1 != 0) { func_00106450(uVar1); }
  PTR_00361fa4 = 0;
  PTR_00361fa0 = 0;
  asm volatile ("" ::: "memory");
  return;
}
