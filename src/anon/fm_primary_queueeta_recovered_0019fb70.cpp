#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u8* D_00352130;
// Compute horizontal xyz length with the copied y lane cleared, scale it,
// and clear the associated status word.

void func_0019fb70(u32 unused,u8* object)
{
 kn::FVector temporary;
 register u32 vector asm("$15")=(u32)object+32;
 asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(temporary) : "r"(vector) : "$8","memory");
 temporary.y=0;
 register f32 length asm("$f1");
 asm volatile("lqc2 $vf1,%1; vmul.xyz $vf1,$vf1,$vf1; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; vsqrt Q,$vf1x; vwaitq; cfc2 $8,$22; mtc1 $8,%0"
              : "=f"(length) : "m"(temporary) : "$8","memory");
 length*=(*(f32*)(D_00352130+28));
 asm("" : "+f"(length) : : "memory");
 *(u32*)(object+0xf8)=0;
 asm("" : : : "memory");
 *(f32*)(object+0xf4)=length;
}
