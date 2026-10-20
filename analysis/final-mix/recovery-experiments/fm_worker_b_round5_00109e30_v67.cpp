#include "../common/types.h"

extern "C" u64 func_00133f80(...);
extern "C" u64 func_00133f60(...);
extern "C" void func_00133ea8(...);
extern "C" void func_00109330(...);
extern "C" void func_00109340(...);

u64 func_00109e30(u32 param_1)
{
  u64 uVar1;
  u32 uVar2 = param_1 & 0xff;
  asm ("nop");
  if (uVar2 != 0) {
    uVar1 = func_00133f80();
  }
  else {
    uVar1 = func_00133f60();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
