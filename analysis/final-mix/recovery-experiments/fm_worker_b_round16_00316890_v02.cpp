#include "../common/types.h"

extern "C" char func_003678f8;
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);

void func_00316890(u32 param_1)
{
  *(volatile u32 *)param_1 = (u32)(long)&func_003678f8;
  func_003167f8();
  func_00106420(param_1);
  asm volatile ("");
  return;
}
