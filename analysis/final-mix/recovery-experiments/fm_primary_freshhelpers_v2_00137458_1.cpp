#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
extern "C" u32 D_00347d30;


void func_00137458(int param_1,s64 param_2)



{

  int iVar1;

  u32 *puVar2;

  

  if ((param_2 == 0xffff) && (param_1 == 1)) {

    iVar1 = 1;

    puVar2 = &D_00347d30;

    asm volatile("" : "+r"(iVar1));
    do {

      puVar2[3] = 0;

      iVar1 = iVar1 + -1;

      asm volatile("" : "+r"(iVar1));
      puVar2 = puVar2 + 4;

    } while (iVar1 != -1);

  }

  return;

}



