#include "../common/types.h"
extern "C" s32 func_003071d0(void*,u32,u32,void*,void*);
extern "C" char func_00307ee8;

void func_00307fe0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  u32 auStack_20 [4];
  
  auStack_20[0] = param_1;
  func_003071d0((u32)(long)&func_00307ee8,auStack_20,param_2,param_3,param_4); asm volatile("" ::: "memory");
  return;
}
