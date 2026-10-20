#include "../common/types.h"
extern "C" f32 D_0036b254;
extern "C" f32 D_0034a788;
extern "C" f32 D_0034a780;
extern "C" f32 D_0034a784;
f32 func_00153610(f32 value)
{
  f32 denominator=D_0034a784 * value + D_0034a780 + D_0034a788 * value * value;
  register f32 *constant asm("$15")=&D_0036b254;
  asm("" : "+r"(constant));
  f32 numerator=*constant;
  f32 result=numerator/denominator;
  if(numerator<result) result=numerator;
  if(result<0.0f) result=0.0f;
  return result;
}
