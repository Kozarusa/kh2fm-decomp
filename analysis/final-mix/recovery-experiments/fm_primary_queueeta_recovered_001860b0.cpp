#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_0016af58(kn::FVector*,const u8*);
// Build the object's vector, then classify the sign of its VU dot product.

s32 func_001860b0(const u8* object,const kn::FVector* plane)
{
 kn::FVector temporary;
 func_0016af58(&temporary,object);
 register f32 dot asm("$f1");
 asm volatile("lqc2 $vf1,%1; lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
              : "=f"(dot) : "m"(temporary),"r"(plane) : "$8","memory");
 if(dot<0.0f) return 1;
 return 0;
}
