#include "../common/types.h"
#include "../kn/fvector.hpp"

s32 func_00163210(const f32* first,const f32* second)
{
 kn::FVector temporary;
 register f32 distance asm("$f2");
 asm volatile("lqc2 $vf1,0(%2); lqc2 $vf2,0(%3); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0; lqc2 $vf1,%0; vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%1"
              : "=m"(temporary),"=f"(distance) : "r"(first),"r"(second) : "$8","memory");
 if(distance<=first[4]+second[4]) return 1;
 return 0;
}
