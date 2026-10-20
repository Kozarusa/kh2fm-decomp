#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" kn::FVector* func_002cdb00(f32,kn::FVector*,const u8*);

kn::FVector* func_002cbf08(kn::FVector* result,const u8* input)
{
 func_002cdb00(*(f32*)(input+24),result,input);
 register f32 length asm("$f0");
 asm volatile("lqc2 $vf1,0(%1); vmul.xyz $vf2,$vf1,$vf1; vaddy.x $vf2,$vf2,$vf2y; vaddz.x $vf2,$vf2,$vf2z; vsqrt Q,$vf2x; vwaitq; cfc2 $8,$22; vaddq.x $vf2,$vf0,Q; mtc1 $8,%0; vnop; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyz $vf1,$vf1,Q; sqc2 $vf1,0(%1)"
              : "=f"(length) : "r"(result) : "$8","memory");
 return result;
}
