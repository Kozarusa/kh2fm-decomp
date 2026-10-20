#include "../common/types.h"

extern "C" u32 func_00294000(u32);
extern "C" u32 func_00295158(u32);

s8 func_00295228(u32 param_1)
{
  u32 *puVar1;
  s8 iVar1;
  puVar1 = (u32 *)((u8 *)func_00294000(0) + 16);
  iVar1 = (s8)((u8 *)puVar1 + (func_00295158(param_1) << 4));
  return iVar1;
}
