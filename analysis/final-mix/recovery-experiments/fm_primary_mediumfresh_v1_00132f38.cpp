#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.
extern "C" s32 func_00132c68(void);
extern "C" s64 func_001325c8(u64,s32,u32);

void func_00132f38(u64 param_1)

{
  int iVar1;
  s64 lVar2;
  
  iVar1 = func_00132c68();
  lVar2 = func_001325c8(param_1,0,*(u32 *)(iVar1 + 0x24));
  if (-1 < lVar2) {
    *(int *)((int)param_1 + 0x274) =
         iVar1 + *(int *)((int)lVar2 * 4 + iVar1 + *(int *)(iVar1 + 0x1c));
  }
  return;
}

