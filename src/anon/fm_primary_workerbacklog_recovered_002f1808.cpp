#include "../common/types.h"

extern "C" u32 func_001708f8(u32,u32);
extern "C" u32 func_00168b38(u32,u32,u32);
extern "C" u32 DAT_00363c20;
asm(".globl DAT_00363c20
	DAT_00363c20 = 0x363c20
");
extern "C" u32 DAT_00363c24;
asm(".globl DAT_00363c24
	DAT_00363c24 = 0x363c24
");
extern "C" u32 DAT_01e3c0d0;
asm(".globl DAT_01e3c0d0
	DAT_01e3c0d0 = 0x1e3c0d0
");

void func_002f1808(void)
{
  u32 uVar1;
  uVar1 = func_001708f8(DAT_00363c20, -1);
  DAT_01e3c0d0 = uVar1;
  uVar1 = func_00168b38(uVar1, 2, 0);
  DAT_00363c24 = *(u32 *)((u8 *)uVar1 + 8);
  return;
}
