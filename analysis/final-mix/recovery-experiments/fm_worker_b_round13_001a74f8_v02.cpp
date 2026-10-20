#include "../common/types.h"

asm(".globl DAT_01c7cb78
	DAT_01c7cb78 = 0x1c7cb78
");

extern "C" u32 DAT_01c7cb78;

extern "C" u32 func_001b8e88(void);
extern "C" void func_0019c218(u32, u32);

void func_001a74f8(void)
{
  u32 iVar1;
  u32 uVar2;
  iVar1 = func_001b8e88();
  uVar2 = DAT_01c7cb78;
  *(u32 *)(uVar2 + 0x9b0) = 0;
  func_0019c218(uVar2, iVar1);
  asm volatile ("");
}
