#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.
extern "C" f32 func_00166d38(u32);
extern "C" f32 func_00166d10(u32,u32);
extern "C" void func_00154cd0(f32,u32,u32);

void func_00155658(u32 param_1)

{
  int iVar1;
  f32 uVar2;
  f32 uVar3;
  
  iVar1 = (int)param_1;
  uVar2 = func_00166d38(*(u32 *)(iVar1 + 0x34));
  uVar3 = func_00166d10(*(u32 *)(iVar1 + 0x24),
                       *(u32 *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x48c) + 4));
  func_00154cd0(uVar3,param_1,1);
  func_00154cd0(uVar2,param_1,2);
  return;
}

