#include "../common/types.h"

extern "C" u32 func_001b9bc8(void);

void func_00185da8(void)
{
  u32 uVar1;
  do {
    uVar1 = func_001b9bc8();
    if (uVar1 == 0) {
      return;
    }
  } while ((*(u32 *)(uVar1 + 0x588) & 0x2) == 0);
  return;
}
