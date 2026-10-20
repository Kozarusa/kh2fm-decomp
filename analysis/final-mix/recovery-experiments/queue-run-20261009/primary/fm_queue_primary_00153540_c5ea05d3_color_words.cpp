#include "../common/types.h"
struct __attribute__((aligned(16))) FloatColor { f32 r,g,b,a; };
extern "C" f32 D_0036b250;
// Convert byte components to floats, then divide all four VU lanes by the
// original symbolic coefficient, preserving the hardware Q operation.
void func_00153540(FloatColor* color,u32 r,u32 g,u32 b,u32 a)
{
 color->r=(f32)(s32)(r&255); color->g=(f32)(s32)(g&255); color->b=(f32)(s32)(b&255); color->a=(f32)(s32)(a&255);
 register const f32* divisor asm("$15")=&D_0036b250;
 asm("" : "+r"(divisor));
 register f32 scale asm("$f0")=*divisor;
 asm volatile("lqc2 $vf1,0(%0); mfc1 $8,%1; qmtc2 $8,$vf2; vdiv Q,$vf0w,$vf2x; vwaitq; vmulq.xyzw $vf1,$vf1,Q; sqc2 $vf1,0(%0); nop"
              : : "r"(color),"f"(scale) : "$8","memory");
}
