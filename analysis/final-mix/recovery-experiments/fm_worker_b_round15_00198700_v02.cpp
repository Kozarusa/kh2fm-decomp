#include "../common/types.h"

extern "C" u32 func_001b9bc8(void);

void func_00198700(void)
{
  u32 uVar1;
  do {
    uVar1 = func_001b9bc8();
    if (uVar1 == 0) {
      return;
    }
  } while (((*(u32 *)(uVar1 + 0x588) & 1) & 0xff) == 0);
  return;
}
