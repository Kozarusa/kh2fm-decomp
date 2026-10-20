#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.
extern "C" s32 func_0017df58(u32);
extern "C" void func_001574a0(u32);
extern "C" void func_001024a8(u32);

void func_00157160(u32 param_1)

{
  s32 lVar1;
  
  lVar1 = func_0017df58(0);
  if ((lVar1 != 0) && ((*(u32 *)((int)lVar1 + 0x588) & 0x400000) != 0)) {
    func_001574a0(*(u32 *)((int)param_1 + 4));
    func_001024a8(param_1);
    return;
  }
  return;
}

