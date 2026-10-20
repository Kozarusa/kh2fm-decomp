#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036defc;
extern "C" f32 D_0036df00;
extern "C" char func_001c6320;
// Scale the supplied vector into the object's effect field, install the
// symbolic callback address, and initialize the effect scalar.

void func_001c6400(u8* object,const kn::FVector* input)
{
 kn::FVector temporary;
 register f32* coefficient asm("$15")=&D_0036defc;
 asm("" : "+r"(coefficient));
 register f32 scale asm("$f0")=*coefficient;
 asm("" : "+f"(scale),"+r"(object) : : "memory");
 register kn::FVector* destination asm("$15")=(kn::FVector*)(u32)((u32)object+64);
 asm("" : "+r"(destination));
 asm volatile("lqc2 $vf1,0(%2); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,%0"
              : "=m"(temporary) : "f"(scale),"r"(input) : "$8","memory");
 *destination=temporary;
 *(u32*)(object+84)=(u32)&func_001c6320;
 asm("" : : : "memory");
 register f32* initial asm("$15")=&D_0036df00;
 asm("" : "+r"(initial));
 *(f32*)(object+76)=*initial;
}
