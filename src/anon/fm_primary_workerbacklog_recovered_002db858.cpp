#include "../common/types.h"

#include "../common/types.h"

extern "C" void func_002cfeb0(u32,u32,u32,u32);
extern "C" void func_002e7308(u32);
extern "C" char func_00362908;

void func_002db858(u32 param_1, u32 param_2, u32 param_3)
{
  func_002cfeb0(param_1, param_2, 3, param_3);
  *(u32 *)((u8 *)param_1 + 2836) = 0xffffffff;
  *(u32 *)param_1 = (u32)(long)&func_00362908;
  func_002e7308(param_1 + 2976);
  asm volatile ("");
  return;
}
