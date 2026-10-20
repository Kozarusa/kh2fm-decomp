#include "../common/types.h"

extern "C" void func_0019f9a8(u32);
extern "C" void func_001c0248(u32);
extern "C" void func_00319fb0(u32);
extern "C" char func_0034ee08;

void func_0031eb68(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&func_0034ee08;
  func_0019f9a8((u32)(long)((u8 *)param_1 + 2568));
  func_001c0248((u32)(long)((u8 *)param_1 + 2640));
  func_00319fb0(param_1);
  return;
}
