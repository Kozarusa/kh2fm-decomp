#include "../common/types.h"

extern "C" void func_0023c098(u32);
extern "C" void func_002369f0(u32);
extern "C" char func_00363880;
extern "C" char func_003637e0;

void func_00325aa0(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&func_00363880;
  func_0023c098(param_1 + 64);
  func_002369f0(param_1 + 40);
  *(u32 *)param_1 = (u32)(long)&func_003637e0;
  asm volatile ("");
  return;
}
