#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.
extern "C" u32 D_0034a42c;
extern "C" s32 func_00150bc0(u32);
extern "C" void func_00150940(u32);
extern "C" void func_001507b8(u32,u64);

void func_0014f578(u64 param_1)

{
  s32 lVar1;
  
  register u64 saved asm("$17")=param_1;
  asm("" : "+r"(saved));
  lVar1 = func_00150bc0(D_0034a42c);
  if (lVar1 != 0) {
    func_00150940(D_0034a42c);
    return;
  }
  func_001507b8(D_0034a42c,saved);
  return;
}
