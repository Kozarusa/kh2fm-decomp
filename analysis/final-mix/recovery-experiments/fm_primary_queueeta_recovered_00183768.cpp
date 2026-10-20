#include "../common/types.h"
#include "../kn/fvector.hpp"
// Copy with the existing self-assignment guard, normalize xyz through VU Q,
// publish the caller's w lane, and return the pre-normalization length.

f32 func_00183768(f32 w,u8* object,const kn::FVector* input)
{
 register kn::FVector* vector asm("$15")=(kn::FVector*)(u32)((u32)object+16);
 asm("" : "+r"(vector));
 *vector=*input;
 register f32 length asm("$f0");
 asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
              : "=f"(length) : "r"(vector) : "$8","memory");
 *(f32*)(object+28)=w;
 return length;
}
