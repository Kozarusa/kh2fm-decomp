#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.
extern "C" f32 D_0036b254;
extern "C" f32 D_0034a788;
extern "C" f32 D_0034a780;
extern "C" f32 D_0034a784;

float func_00153610(float param_1)

{
  float fVar1;
  
  fVar1 = D_0036b254 / (D_0034a788 * param_1 * param_1 + D_0034a780 + D_0034a784 * param_1);
  if (D_0036b254 < fVar1) {
    fVar1 = D_0036b254;
  }
  if (fVar1 < 0.0f) {
    fVar1 = 0.0f;
  }
  return fVar1;
}

