#include "../common/types.h"

extern "C" void func_0030f620(s32,s32);

void func_0030f6a0(s32 param_1)
{
  asm volatile("move $a1,$a0
	lui $a0,0xb000
	j 0x0030f620
	ori $a0,$a0,0x1010" ::: "a0","a1","memory");
}
