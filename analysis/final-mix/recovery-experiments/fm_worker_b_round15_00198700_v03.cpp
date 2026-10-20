#include "../common/types.h"

extern "C" u32 func_001b9bc8(u32);

void func_00198700(u32 param_1)
{
  u32 uVar1;
  do {
    uVar1 = func_001b9bc8(param_1);
    if (uVar1 == 0) {
      return;
    }
  } while (((*(u32 *)(uVar1 + 0x588) & 1) & 0xff) == 0);
  return;
}
