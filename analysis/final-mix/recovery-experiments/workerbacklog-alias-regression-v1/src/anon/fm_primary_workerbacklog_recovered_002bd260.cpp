#include "../common/types.h"

extern "C" void func_002fee78(u32,u32,u32);
extern "C" void func_002ff3fc(u32);
extern "C" char func_01e2bba0;

extern "C" char func_00374fa8;

u32 func_002bd260(u32 param_1)
{
  u32 uVar1;
  uVar1 = (u32)(long)&func_01e2bba0;
  func_002fee78(uVar1, (u32)(long)&func_00374fa8, param_1);
  func_002ff3fc(uVar1);
  return uVar1;
}
