#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036b4b4;
extern "C" f32 D_0036b4b8;
// Classify the projected difference with the original two less-than tests.
s32 func_00163828(const f32* origin,const f32* point,const f32* normal)
{
 kn::FVector temporary;
 register f32 dot asm("$f1");
 asm volatile("lqc2 $vf1,0(%3); lqc2 $vf2,0(%2); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0; lqc2 $vf1,%0; lqc2 $vf2,0(%4); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%1"
              : "=m"(temporary),"=f"(dot) : "r"(origin),"r"(point),"r"(normal) : "$8","memory");
 register const f32* low asm("$15")=&D_0036b4b4;
 asm("" : "+r"(low));
 register f32 lower asm("$f0")=*low;
 asm volatile("" : "+f"(lower),"+f"(dot) : : "$2");
 if(dot<lower) return 1;
 asm volatile("" : : : "$15","memory");
 register const f32* high asm("$15")=&D_0036b4b8;
 asm volatile("" : "+r"(high) : : "memory");
 if(*high<dot) return 0;
 return 2;
}
