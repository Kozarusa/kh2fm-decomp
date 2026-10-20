#include "../common/types.h"
extern "C" s32 func_00139d78(u32);
extern "C" void func_00138c10(u32,s32);
extern "C" void func_00139510(u32);
// Restore original first helper argument; verify complete range.
void func_0013e4b8(u32 param_1)

{
  s32 lVar1;
  int iVar2;
  
  register u32 callObject asm("$4")=param_1; asm volatile("" : "+r"(callObject)); iVar2=(s32)callObject+0x1c0;
  lVar1 = func_00139d78(callObject);
  if (lVar1 != 0) {
    func_00138c10(param_1,*(int *)((int)param_1 + 0x184) + -1);
    lVar1 = func_00139d78(iVar2);
    if (lVar1 != 0) {
      func_00139510(iVar2);
      return;
    }
  }
  return;
}
