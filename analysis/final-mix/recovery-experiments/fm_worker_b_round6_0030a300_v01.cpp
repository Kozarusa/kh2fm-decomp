#include "../common/types.h"

asm(".globl DAT_0036616c
	DAT_0036616c = 0x36616c
");

extern "C" u32 DAT_0036616c;
extern "C" void SignalSema(u32);

void func_0030a300(void)
{
  SignalSema(DAT_0036616c);
}
