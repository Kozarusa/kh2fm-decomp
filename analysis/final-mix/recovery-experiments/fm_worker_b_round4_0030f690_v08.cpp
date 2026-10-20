#include "../common/types.h"

extern "C" void func_0030f620(u32,u32);

void func_0030f690(u32 param_1)
{
  u32 uVar1;
  asm("" : "+r"(param_1));
  uVar1 = 0xb0001000u;
  asm("" : "+r"(uVar1));
  func_0030f620(uVar1,param_1);
}
