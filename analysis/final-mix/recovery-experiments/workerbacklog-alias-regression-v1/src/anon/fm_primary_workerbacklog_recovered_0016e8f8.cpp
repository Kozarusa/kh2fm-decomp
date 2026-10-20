#include "../common/types.h"

asm(".globl PTR_0035dc28
	PTR_0035dc28 = 0x35dc28
");

extern "C" u32 PTR_0035dc28;
extern "C" u64 func_001b1448(u32);
extern "C" void func_001d3390(u64);

void func_0016e8f8(void)
{
  u64 uVar1;
  uVar1 = func_001b1448(PTR_0035dc28);
  func_001d3390(uVar1);
}
