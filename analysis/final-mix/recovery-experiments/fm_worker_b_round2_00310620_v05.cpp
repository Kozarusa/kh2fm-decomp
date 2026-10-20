#include "../common/types.h"
extern "C" s32 func_0030edb0(...);
extern "C" void func_0030ee00(...);
extern "C" s32 func_003105b0(...);
long long func_00310620(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb0() != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00();
  }
  return (u32)uVar2;
}
