#include "../common/types.h"

extern "C" s32 D_0035f404;
extern "C" u32 D_0035f410;
extern "C" u32 func_0028cdb8(u32 index);

// Preserve original registry aliases.
void func_0028ce38() asm("_ZN2Tz10MenuCursor9DeleteAllEz");

void func_0028ce38()
{
  s32 index = 0;
  if (D_0035f404 > 0) {
    do {
      func_0028cdb8(index);
      index++;
    } while (index < D_0035f404);
  }
  D_0035f410 = 0;
}
