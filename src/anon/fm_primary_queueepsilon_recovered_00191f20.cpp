#include "../common/types.h"
extern "C" u32 func_002fd248(u64,s32,s32,s32,s32);
extern "C" char func_0031eec8;

int func_00191f20(int param_1,u64 param_2)

{
  u32 lVar1;
  int iVar2;
  
  lVar1 = func_002fd248(param_2 & 0xffffffffffff7fff,param_1 + 8,*(u32 *)(param_1 + 4),8,
                       (s32)(long)&func_0031eec8);
  iVar2 = 0;
  if (lVar1 != 0) {
    iVar2 = param_1 + *(int *)((int)lVar1 + 4);
  }
  return iVar2;
}
