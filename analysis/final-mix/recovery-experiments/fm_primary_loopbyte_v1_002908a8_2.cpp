#include "../common/types.h"
void func_002908a8(int param_1)

{
  register s32 iVar1 asm("$13");
  register s32 iVar2 asm("$14");
  int iVar3;
  
  *(u32 *)(param_1 + 4) = 0;
  *(u8 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 8) = 0;
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar3 = *(int *)(param_1 + 0x14);
    while( true ) {
      iVar2 = iVar1 * 4;
      iVar1 = iVar1 + 1; asm volatile("" : "+r"(iVar1) : "r"(iVar2));
      *(u32 *)(iVar2 + iVar3) = 0;
      if (*(int *)(param_1 + 0xc) <= iVar1) break;
      iVar3 = *(int *)(param_1 + 0x14);
    }
  }
  return;
}
