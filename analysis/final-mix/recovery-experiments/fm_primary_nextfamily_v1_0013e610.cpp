#include "../common/types.h"
// Provisional compiler proposal; complete-range proof is required.
extern "C" void func_0013e2d8(s32,u64,u32);
extern "C" u32 D_003486a4;
extern "C" u32 D_003486a0;

int func_0013e610(u64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = D_003486a4;
  iVar1 = *(int *)(D_003486a4 + 0x1fa4) + -1;
  *(int *)(D_003486a4 + 0x1fa4) = iVar1;
  iVar2 = iVar2 + *(int *)(iVar1 * 4 + iVar2 + 0x1f80) * 0x380;
  func_0013e2d8(iVar2,param_1,D_003486a0 + 0x20);
  return iVar2;
}

