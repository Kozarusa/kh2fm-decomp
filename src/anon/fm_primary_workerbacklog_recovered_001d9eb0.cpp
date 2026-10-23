#include "../common/types.h"

extern "C" char func_00352908;
extern "C" void func_001980d0(u32, u32, u32, u32);

void func_001d9eb0(u32 param_1, u32 param_2, u32 param_3)
{
  u32 *puVar1;
  func_001980d0(param_1, param_2, 10, param_3);
  puVar1 = (u32 *)param_1;
  puVar1[0x27e] = 0;
  puVar1[0x27d] = 0;
  *puVar1 = (u32)(long)&func_00352908;
  return;
}
