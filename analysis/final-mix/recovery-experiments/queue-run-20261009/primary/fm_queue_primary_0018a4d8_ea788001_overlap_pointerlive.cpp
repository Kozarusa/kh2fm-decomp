#include "../common/types.h"
#include "../kn/fvector.hpp"
// Compare squared center distance with squared summed radii; preserve the
// intermediate guarded vector copy used by the original constructor chain.
s32 func_0018a4d8(const u8* first,const u8* second)
{
 kn::FVector temporary,difference;
 register const kn::FVector* point asm("$14")=(const kn::FVector*)(u32)((u32)second+16);
 asm("" : "+r"(point),"+r"(first));
 register const kn::FVector* origin asm("$15")=(const kn::FVector*)(u32)((u32)first+16);
 asm("" : "+r"(origin) : : "$13");
 register kn::FVector* delta asm("$13")=&difference;
 asm("" : "+r"(delta));
 asm volatile("lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%2); nop"
              : : "r"(point),"r"(origin),"r"(delta) : "memory");
 temporary=*delta;
 register f32 squared asm("$f0");
 asm volatile("lqc2 $vf1,%1; lqc2 $vf2,%1; vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
              : "=f"(squared) : "m"(temporary) : "$8","memory");
 f32 radii=*(const f32*)(first+4)+*(const f32*)(second+4);
 if(squared<radii*radii) return 1;
 return 0;
}
