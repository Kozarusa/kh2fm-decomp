#include "../common/types.h"

extern "C" u64 func_00133f80(...);
extern "C" u64 func_00133f60(...);
extern "C" void func_00133ea8(...);
extern "C" void func_00109330(...);
extern "C" void func_00109340(...);

u64 func_00109e30(u32 param_1)
{
  u64 uVar1;
  u8 uVar2;
  uVar2 = (u8)param_1;
  if (!uVar2) goto L_zero;
  uVar1 = func_00133f80();
  goto L_end;
L_zero:
  uVar1 = func_00133f60();
L_end:
  func_00133ea8();
  func_00109330();
  func_00109340();
  return uVar1;
}
