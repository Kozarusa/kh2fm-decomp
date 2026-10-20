#include "../common/types.h"

extern "C" void func_0030edb0(u32);
extern "C" u32 func_00310230(u32);
extern "C" void func_0030ee00(u32);

u32 func_003102e0(u32 param_1)
{
  u32 uVar1;
  func_0030edb0(param_1);
  uVar1 = func_00310230(param_1);
  if (uVar1 != 0) {
    func_0030ee00(uVar1);
    return uVar1;
  }
  return param_1;
}
