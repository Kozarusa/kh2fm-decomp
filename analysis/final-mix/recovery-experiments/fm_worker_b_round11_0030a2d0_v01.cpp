#include "../common/types.h"

asm(".globl DAT_0036616c\n\tDAT_0036616c = 0x36616c\n");

extern "C" u32 DAT_0036616c;
extern "C" void func_0030a278();
extern "C" void func_00305660(u32);

u64 func_0030a2d0(void)
{
  func_0030a278();
  func_00305660(DAT_0036616c);
  return 0;
}
