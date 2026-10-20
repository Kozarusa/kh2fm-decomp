#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.

int * func_00124c48(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  piVar1 = (int *)0x0;
  if (*(int *)(iVar2 + 0xc) != 0) {
    piVar1 = (int *)(iVar2 + *(int *)(iVar2 + 8));
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (iVar2 == -1) {
      return (int *)0x0;
    }
    do {
      if (iVar2 == param_2) {
        return piVar1;
      }
      piVar1 = piVar1 + piVar1[1] * 4 + 4;
      iVar2 = *piVar1;
    } while (iVar2 != -1);
  }
  return (int *)0x0;
}

