#include "../common/types.h"

asm(".globl PTR_00365c48\n\tPTR_00365c48 = 0x365c48\n");

extern "C" u32 PTR_00365c48;
extern "C" void func_00316d18(u32, u32);
extern "C" void func_00315440();

void func_003155c0(void)
{
  func_00316d18(0x3785f8, *(u32 *)(PTR_00365c48 + 0xc));
  func_00315440();
}
