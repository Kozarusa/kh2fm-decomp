#include "../common/types.h"

extern "C" void func_0011cdf0(u32,u32,u32,u32,u32);
extern "C" void func_002f25a0(u32,u32);
void func_002eee68(u32 param_1)
{
  func_0011cdf0(*(u32 *)(param_1 + 0x44), (u32)(long)((u8 *)param_1 + 0x50),
                (u32)(long)((u8 *)param_1 + 0x150), (u32)(long)((u8 *)param_1 + 0x190), 0);
  func_002f25a0(0, 0);
  return;
}
