#include "../common/types.h"

extern "C" void func_00185ed8(u32,u32,u32,u32);
extern "C" char func_00361810;

void func_002be7b8(u32 param_1, u32 param_2, u32 param_3)
{
  u32 uVar1;
  func_00185ed8(param_1, param_2, 4, param_3);
  uVar1 = *(u32 *)((u8 *)param_1 + 1416);
  uVar1 = uVar1 | 0x4000;
  *(u32 *)param_1 = (u32)(long)&func_00361810;
  *(u32 *)((u8 *)param_1 + 1416) = uVar1;
  return;
}
