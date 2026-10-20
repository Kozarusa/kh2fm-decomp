#include "../common/types.h"

extern "C" u64 func_003088f8(u32,u32,u32,u32,u32,u32);

u32 func_003091c8(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  u32 uVar1;
  uVar1 = func_003088f8(0x800008, param_4, 64, 0, 0, 0);
  return (u32)(uVar1 == 0) * 2048;
}
