#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.
extern "C" f32 D_0036abec;
extern "C" f32 D_0036abf0;

int func_001317a8(float param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_2 + 4) + 0x24);
  iVar2 = (int)((param_1 * *(float *)(*(int *)(param_2 + 4) + 0x58)) / D_0036abec + D_0036abf0);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (iVar1 <= iVar2) {
    iVar2 = iVar1 + -1;
  }
  return iVar2;
}

