#include "../common/types.h"

extern "C" void func_0030f620(s32,s32);

void func_0030f6a0(s32 param_1) __attribute__((noreturn));

void func_0030f6a0(s32 param_1)
{
  asm volatile("move $5,$4
	lui $4,0xb000
	j 0x0030f620
	ori $4,$4,0x1010" ::: "$4","$5","memory");
}
