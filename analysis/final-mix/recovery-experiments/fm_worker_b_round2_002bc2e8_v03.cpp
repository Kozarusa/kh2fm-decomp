#include "../common/types.h"


extern "C" s32 func_002bc158(void);
extern "C" void func_002bb310(s32,u32,u32,u32);

u32 func_002bc2e8(u32 param_1,u32 param_2,u32 param_3)
{
  s32 lVar2;
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  lVar2 = func_002bc158();
  uVar2 = param_2;
  uVar3 = param_1;
  uVar1 = 0;
  if (lVar2 != 0) {
    func_002bb310(lVar2,uVar3,uVar2,param_3);
    uVar1 = *(u32 *)((int)lVar2 + 0x14);
  }
  return uVar1;
}

