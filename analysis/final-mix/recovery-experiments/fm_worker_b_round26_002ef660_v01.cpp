#include "../common/types.h"

#include "../common/types.h"

extern "C" u32 func_0023a918(u32);

u32 func_002ef660(u32 param_1, u32 param_2)
{
  volatile u8 *puVar1;
  u32 uVar1;
  puVar1 = (volatile u8 *)param_1;
  uVar1 = func_0023a918(param_2 + 468);
  puVar1[0] = uVar1 & 0xff;
  puVar1[3] = (uVar1 >> 24) & 0xff;
  puVar1[1] = (uVar1 >> 8) & 0xff;
  puVar1[2] = (uVar1 >> 16) & 0xff;
  return param_1;
}
