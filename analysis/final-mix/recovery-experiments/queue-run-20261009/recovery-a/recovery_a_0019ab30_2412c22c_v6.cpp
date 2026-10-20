#include "../common/types.h"
extern "C" s32 func_00195700(s32);
extern "C" char D_0034f250;

u32 func_0019ab30(int param_1)

{
  s32 lVar1;
  int iVar2;
  
  lVar1 = func_00195700((s32)(long)&D_0034f250);
  if (lVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x18) = iVar2;
    asm volatile ("" ::: "memory");
    *(int *)(param_1 + 0x1c) = iVar2;
  }
  if(lVar1 != 0) {u32 result=0; asm volatile ("" : "+r"(result)); return result;}
  return 1;
}
