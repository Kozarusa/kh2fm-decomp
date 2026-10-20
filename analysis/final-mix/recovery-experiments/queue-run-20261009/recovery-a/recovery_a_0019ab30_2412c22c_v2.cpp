#include "../common/types.h"
extern "C" u64 func_00195700(...);
extern "C" char D_0034f250;

u32 func_0019ab30(int param_1)

{
  s32 lVar1;
  int iVar2;
  
  u32 flag = 0;
  lVar1 = func_00195700((s32)(long)&D_0034f250);
  if (lVar1 == 0) {
    flag = 1;
    iVar2 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x18) = iVar2;
    *(int *)(param_1 + 0x1c) = iVar2;
  }
  asm volatile ("" : "+r"(flag));
  return flag;
}
