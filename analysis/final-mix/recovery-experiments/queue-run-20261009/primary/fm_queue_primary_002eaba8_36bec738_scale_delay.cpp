#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_00363440;
// Scale all four source lanes through the VU, preserving guarded vector copy.
kn::FVector* func_002eaba8(kn::FVector* result,u32 unused,const u8* object)
{
 kn::FVector temporary;
 register f32 scale asm("$f0")=D_00363440;
 register u32 vector asm("$6")=(u32)object+16;
 asm volatile("lqc2 $vf1,0(%2); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,%0; nop"
              : "=m"(temporary) : "f"(scale),"r"(vector) : "$8","memory");
 *result=temporary;
 return result;
}

