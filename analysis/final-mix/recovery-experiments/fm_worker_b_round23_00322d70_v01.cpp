#include "../common/types.h"

extern "C" void func_0023c098(u32);
extern "C" void func_002369f0(u32);
extern "C" char func_0036eb98;
extern "C" char func_00347f98;

void func_00322d70(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&func_0036eb98;
  func_0023c098(param_1 + 48);
  func_002369f0(param_1 + 24);
  *(u32 *)param_1 = (u32)(long)&func_00347f98;
  asm volatile ("");
  return;
}
