#include "../common/types.h"
#include "../kn/fvector.hpp"
// Preserve the explicit temporary vector and VU square-root sequence.
s32 func_00163268(const f32* object,const f32* point,f32* result)
{
 kn::FVector temporary;
 register f32 distance asm("$f1");
 asm volatile("lqc2 $vf1,0(%2); lqc2 $vf2,0(%3); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0; lqc2 $vf1,%0; vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%1"
              : "=m"(temporary),"=f"(distance) : "r"(object),"r"(point) : "$8","memory");
 *result=distance;
 if(distance<=object[4]) return 1;
 return 0;
}
