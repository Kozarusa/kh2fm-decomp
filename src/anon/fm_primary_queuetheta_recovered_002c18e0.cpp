#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" void func_0017f488(u32,s32,f32,f32);
extern "C" void func_002c5f78(u8*);

void func_002c18e0(u32 unused,u8* object)
{
 kn::FVector temporary;
 register const kn::FVector* input asm("$15")=(const kn::FVector*)(u32)((u32)object+16);
 asm("" : "+r"(input));
 register kn::FVector* output asm("$13")=(kn::FVector*)(u32)((u32)object+32);
 asm("" : "+r"(output));
 register u8* configuration asm("$14")=*(u8**)(object+0x12c);
 register f32 scale asm("$f0")=*(f32*)(configuration+36);
 asm volatile("lqc2 $vf1,0(%2); mfc1 $8,%1; qmtc2 $8,$vf2; vmulx.xyzw $vf1,$vf1,$vf2x; sqc2 $vf1,%0"
              : "=m"(temporary) : "f"(scale),"r"(input) : "$8","memory");
 *output=temporary;
 func_0017f488((u32)object+0x140,154,0.0f,0.0f);
 func_002c5f78(object);
}
