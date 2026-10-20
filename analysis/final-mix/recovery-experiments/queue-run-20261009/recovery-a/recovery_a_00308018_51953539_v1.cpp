#include "../common/types.h"
extern "C" s32 func_003071d0(void*,u32,u32,void*,void*);
extern "C" char func_00307ee8;

void func_00308018(u32 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5,u64 param_6,u64 param_7,u64 param_8)

{
  u32 auStack_90 [4];
  u64 uStack_28;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  auStack_90[0] = param_1;
  uStack_28 = param_4;
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  func_003071d0((s32)(long)&func_00307ee8,auStack_90,param_2,param_3,&uStack_28);
  return;
}
