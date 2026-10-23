#include "../common/types.h"

asm(".globl DAT_01e3c190\n\tDAT_01e3c190 = 0x1e3c0d0\n");

extern "C" u32 DAT_01e3c190;
extern "C" u32 func_00168b38(u32, u32, u32);

u32 func_002f1898(void)
{
  u32 iVar1;
  iVar1 = func_00168b38(DAT_01e3c190, 0x19, 0);
  return *(u32 *)(iVar1 + 8);
}
