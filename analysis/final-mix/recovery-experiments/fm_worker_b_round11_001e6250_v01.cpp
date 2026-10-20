#include "../common/types.h"

asm(".globl DAT_00354690\n\tDAT_00354690 = 0x354690\n.globl DAT_00354694\n\tDAT_00354694 = 0x354694\n");

extern "C" u32 DAT_00354690;
extern "C" u32 DAT_00354694;
extern "C" void func_001e60b0();

void func_001e6250(void)
{
  u32 *puVar1;
  func_001e60b0();
  puVar1 = &DAT_00354690;
  *puVar1 = 0;
  *(puVar1 + 1) = -1;
}
