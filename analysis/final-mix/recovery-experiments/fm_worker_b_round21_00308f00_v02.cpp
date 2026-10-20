#include "../common/types.h"

extern "C" u64 func_003088f8(u32,u32,u32,u32,u32,u32);

u32 func_00308f00(u32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
  u32 *puVar1;
  u32 uVar1;
  puVar1 = (u32 *)param_4;
  uVar1 = func_003088f8(0x800008, puVar1, 64, puVar1[9], puVar1[10], puVar1[11]);
  return (u32)(uVar1 == 0) * 2048;
}
