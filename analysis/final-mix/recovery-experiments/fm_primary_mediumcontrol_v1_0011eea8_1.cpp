#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.


void func_0011eea8(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  register s32 iVar3 asm("$15");

  u32 uVar4;

  

  iVar3 = *(int *)(param_1 + 8);

  asm volatile("" : "+r"(iVar3));
  if (__builtin_expect(iVar3 == param_2,0)) {

    *(u32 *)(param_1 + 8) = *(u32 *)(param_2 + 4);

    return;

  }

  iVar1 = *(int *)(iVar3 + 4);

  if (iVar1 != 0) {

    if (iVar1 == param_2) {

      uVar4 = *(u32 *)(param_2 + 4);

      goto LAB_0011eeec;

    }

    iVar2 = *(int *)(iVar1 + 4);

    iVar3 = iVar1;

    while( true ) {

      iVar1 = iVar2;

      if ((iVar1 == 0) || (iVar1 == param_2)) break;

      iVar2 = *(int *)(iVar1 + 4);

      iVar3 = iVar1;

    }

  }

  uVar4 = *(u32 *)(param_2 + 4);

LAB_0011eeec:

  *(u32 *)(iVar3 + 4) = uVar4;

  return;

}



