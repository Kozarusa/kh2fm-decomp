#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);
extern "C" s32 func_0013e610(u32);
typedef void code(u32);

void func_0013e5a8(u32 param_1)

{
  s32 lVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1;
  lVar1 = func_00139d78(param_1);
  if (lVar1 != 0) {
    (**(code **)(*piVar2 + 0x14))(param_1);
  }
  lVar1 = func_00139d78(piVar2 + 0x70);
  if (lVar1 != 0) {
    func_00139510(piVar2 + 0x70);
  }
  func_0013e610(piVar2[0x6d]);
  return;
}
