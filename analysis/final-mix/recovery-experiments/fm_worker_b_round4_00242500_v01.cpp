#include "../common/types.h"

extern "C" u32 func_002424c0(void);
extern "C" u32 func_001058e8(void);

u32 func_00242500(u32 param_1)
{
  u32 uVar1;
  u32 *puVar1;
  u32 uVar2;
  if (func_002424c0() != 0) {
    puVar1 = (u32 *)func_001058e8();
    uVar1 = *(u32 *)((char *)puVar1 + 0x2440) + param_1;
  }
  else {
    puVar1 = (u32 *)func_001058e8();
    uVar1 = 999999;
  }
  puVar1 = (u32 *)func_001058e8();
  *(u32 *)((char *)puVar1 + 0x2440) = uVar1;
  uVar2 = func_001058e8();
  return *(u32 *)((char *)uVar2 + 0x2440);
}
