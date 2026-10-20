#include "../common/types.h"

asm(".globl DAT_0036616c\n\tDAT_0036616c = 0x36616c\n");

extern "C" u32 *DAT_0036616c;
extern "C" void func_00305640(u32);

void func_0030a300(void)
{
  func_00305640(*DAT_0036616c);
}
