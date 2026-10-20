#include "../common/types.h"

asm(".globl PTR_00351214
	PTR_00351214 = 0x351214
");

extern "C" u32 PTR_00351214;
extern "C" void func_001a3c88();
extern "C" void func_001029e8(u32);

void func_001b92d0(void)
{
  func_001a3c88();
  func_001029e8(PTR_00351214);
}
