#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" s64 func_00141080(void);
extern "C" void func_001ad990(u32,u32,u32,u32);
extern "C" u32 D_00348754;
extern "C" u32 D_0036ae80;
extern "C" u32 D_00348750;

void func_00141010(u32 param_1)

{
  s64 lVar1;
  
  lVar1 = func_00141080();
  if ((lVar1 != 0) && (D_00348754 != 0)) {
    func_001ad990(0,D_0036ae80,param_1,D_00348754 + 0x834);
    D_00348750 = 0;
  }
  return;
}

