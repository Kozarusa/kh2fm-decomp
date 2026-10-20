#include "../common/types.h"

extern "C" u32 func_001de168(u32,u32,u32,u32,u32,u32);

u32 func_00174858(u32 param_1)
{
  u32 *puVar1;
  u32 uVar1;
  puVar1 = (u32 *)param_1;
  uVar1 = func_001de168(*puVar1, puVar1[1], puVar1[3], 1, puVar1[4], *(u32 *)(puVar1[2] + 1));
  *puVar1 = uVar1;
  return uVar1;
}
