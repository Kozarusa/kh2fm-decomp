#include "../common/types.h"

extern "C" char func_00367848;
extern "C" void func_003167f8(u32);
extern "C" void func_00106420(u32);

void func_00315700(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&func_00367848;
  func_003167f8(param_1);
  func_00106420(param_1);
  asm volatile ("");
  return;
}
