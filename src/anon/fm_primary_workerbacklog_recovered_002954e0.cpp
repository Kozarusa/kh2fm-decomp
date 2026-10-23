#include "../common/types.h"

// Preserve original registry aliases.
void func_002954e0(void) asm("_ZN2Tz10JmWorldSel11isWorldOpenEi");

extern "C" u64 func_002953c8();
extern "C" void func_002941a8(u64);

void func_002954e0(void)
{
  u64 uVar1;
  uVar1 = func_002953c8();
  func_002941a8(uVar1);
  asm volatile("");
}
