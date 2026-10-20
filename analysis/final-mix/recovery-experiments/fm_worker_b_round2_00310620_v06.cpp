#include "../common/types.h"
struct pair { int lo; int hi; };
extern "C" s32 func_0030edb0(pair);
extern "C" void func_0030ee00(pair);
extern "C" s32 func_003105b0(s32);
u32 func_00310620(u32 param_1)
{
  bool lVar1;
  u32 uVar2;
  lVar1 = func_0030edb0(pair{0,0}) != 0;
  uVar2 = func_003105b0(param_1);
  if (lVar1 != 0) {
    func_0030ee00(pair{0,0});
  }
  return uVar2;
}
