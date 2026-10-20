#include "../common/types.h"

extern "C" void func_002fee78(u32,u32,u32);
extern "C" void func_002ff3fc(u32);
extern "C" char func_01e2a568;

extern "C" char func_00374f70;

u64 func_002ba0b0(u64 param_1)
{
  u64 uVar1;
  uVar1 = (u32)(long)&func_01e2a568;
  func_002fee78(uVar1, (u32)(long)&func_00374f70, param_1);
  func_002ff3fc(uVar1);
  return uVar1;
}
