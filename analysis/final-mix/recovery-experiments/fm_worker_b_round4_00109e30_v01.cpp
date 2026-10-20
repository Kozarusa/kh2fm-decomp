#include "../common/types.h"

extern "C" u32 func_00133f60();
extern "C" u32 func_00133f80();
extern "C" void func_00133ea8();
extern "C" void func_00109330();
extern "C" void func_00109340();

u32 func_00109e30(u8 param_1)
{
  u32 uVar1;
  if (param_1 == 0) {
    uVar1 = func_00133f60();
  }
  else {
    uVar1 = func_00133f80();
  }
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
