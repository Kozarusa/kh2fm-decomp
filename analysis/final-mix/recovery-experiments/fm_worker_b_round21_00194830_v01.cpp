#include "../common/types.h"

extern "C" u64 func_001947c0(void);

u32 func_00194830(u32 param_1, u32 param_2, u32 param_3)
{
  u64 uVar1;
  u32 uVar2;
  uVar1 = func_001947c0();
  if (uVar1 == 0) { return 0; }
  uVar2 = *(u32 *)uVar1;
  uVar2 = uVar2 & (1 << param_3);
  return (u32)(uVar2 != 0);
}
