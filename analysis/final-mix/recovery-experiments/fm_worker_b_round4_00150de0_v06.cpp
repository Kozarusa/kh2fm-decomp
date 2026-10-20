#include "../common/types.h"

extern "C" void func_00150e00(u32,u32,u32,u32,s32);

void func_00150de0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,s32 param_5)
{
  param_5 = -1;
  *(u32 *)(param_1 + 0x19a0) = (u32)param_5;
  func_00150e00(param_1,param_2,param_3,param_4,param_5);
}
