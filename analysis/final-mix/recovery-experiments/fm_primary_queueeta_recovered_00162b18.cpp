#include "../common/types.h"
// Preserve both less-than tests; replacing their inverses with ordered <= or
// >= changes the original result for unordered floating-point operands.

s32 func_00162b18(const f32* object,const f32* plane,f32* result)
{
 register f32 dot asm("$f1");
 asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
              : "=f"(dot) : "r"(object),"r"(plane) : "$8","memory");
 dot+=plane[3];
 *result=dot;
 if(object[4]<dot) return 0;
 if(dot<0.0f) return 0;
 return 1;
}
