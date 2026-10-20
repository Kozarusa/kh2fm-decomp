#include "../common/types.h"
// Provisional recovery; complete-range proof is required.

void func_00144570(float *param_1,float *param_2)

{
  float fVar1;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (&fStack_10 == param_2) {
    fVar1 = param_2[4];
  }
  else {
    fStack_10 = *param_2;
    fStack_c = param_2[1];
    fStack_8 = param_2[2];
    fVar1 = param_2[4];
  }
  param_1[3] = fStack_10 + fVar1;
  param_1[4] = fStack_c + fVar1;
  param_1[5] = fStack_8 + fVar1;
  *param_1 = fStack_10 - fVar1;
  param_1[1] = fStack_c - fVar1;
  param_1[2] = fStack_8 - fVar1;
  return;
}

