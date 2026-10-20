#include "../common/types.h"
extern "C" u32 func_002fee78(...);
extern "C" char D_0036b3c0;

int func_0015b4f8(int param_1,u64 param_2,u32 *param_3)

{
  int iVar1;
  int iVar2;
  u32 more;
  char *pcVar3;
  char acStack_30 [16];
  
  func_002fee78(acStack_30,(s32)(long)&D_0036b3c0,param_2);
  iVar1 = 0;
  iVar2 = 0;
  do {
    pcVar3 = acStack_30 + iVar2;
    iVar2 = iVar2 + 1;
    more = iVar2 < 16;
    asm volatile ("" : "+r"(more));
    if (*pcVar3 == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    s32 index = *pcVar3 - 0x30;
    asm volatile ("" : "+r"(index));
    *param_3 = *(u32 *)(index*4 + param_1);
    param_3 = param_3 + 1;
  } while (more);
  return iVar1;
}
