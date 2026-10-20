#include "../common/types.h"

asm(".globl DAT_003511c1\n\tDAT_003511c1 = 0x3511c1\n");
asm(".globl PTR_003511b8\n\tPTR_003511b8 = 0x3511b8\n");

extern "C" u8 DAT_003511c1;
extern "C" u32 PTR_003511b8;
extern "C" void func_001b7f88(...);

u32 func_001b81e8(void)
{
  func_001b7f88();
  DAT_003511c1 = 1;
  return PTR_003511b8;
}
