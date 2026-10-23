#include "../common/types.h"

// Preserve original registry aliases.
u32 func_001b5c78(u32 param_1) asm("_ZN2YS5LIMIT17reset_hit_counterEv");

extern "C" void func_001d2180(u32);
extern "C" void func_001d20a8(u32);

u32 func_001b5c78(u32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = param_1 + 104;
  uVar2 = *(u32 *)(uVar1 + 44);
  func_001d2180(uVar1);
  func_001d20a8(uVar1);
  return uVar2;
}
