#include "../common/types.h"
extern "C" u32 func_00313b80(f32);
extern "C" u32 func_002fdfc8(...);
extern "C" char D_00370c68;

void func_00223608(u32 param_1,f32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  uVar1 = func_00313b80(*param_2);
  uVar2 = func_00313b80(param_2[1]);
  uVar3 = func_00313b80(param_2[2]);
  uVar4 = func_00313b80(param_2[3]);
  func_002fdfc8((s32)(long)&D_00370c68,param_1,uVar1,uVar2,uVar3,uVar4);
  return;
}
