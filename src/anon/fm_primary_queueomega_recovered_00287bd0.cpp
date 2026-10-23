#include "../common/types.h"
extern "C" u32 D_0035f2f8;
extern "C" void func_00287c20(void);
extern "C" void func_00287c78(u64);

// Preserve original registry aliases.
void func_00287bd0(u32 value,u64 payload) asm("_ZN2Tz8MenuBase14NextModeToModeEz");

void func_00287bd0(u32 value,u64 payload)
{
 D_0035f2f8=value;
 func_00287c20();
 func_00287c78(payload);
}
