#include "../common/types.h"
struct __attribute__((aligned(16))) FloatVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) IntegerVector { s32 x,y,z,w; };
// Convert xy to four fractional bits and zw to integers. Test the original
// VU MAC flags and replace w with the VI1 clipping marker when required.

void func_00222800(IntegerVector* result,const FloatVector* input)
{
 asm volatile("lqc2 $vf1,0(%0); vftoi4.xy $vf2,$vf1; vftoi0.zw $vf2,$vf1" : : "r"(input) : "memory");
 register u64 upper asm("$2");
 asm("lui %0,0x4580; dsll %0,%0,16; ori %0,%0,0x4580; dsll %0,%0,16" : "=r"(upper));
 register u32 flags asm("$2");
 asm volatile("qmtc2 %1,$vf29; ctc2 $0,$16; vsub.wxy $vf0,$vf1,$vf0; vsub.xy $vf0,$vf29,$vf1; vnop; vnop; vnop; vnop; cfc2 %0,$16"
              : "=r"(flags) : "r"(upper) : "memory");
 if(flags&0xc0) {
  asm volatile("addiu $2,$0,0; ori $2,$0,0x8000; ctc2 $2,$1; vmfir.w $vf2,$vi1" : : : "$2","memory");
 }
 asm volatile("sqc2 $vf2,%0; nop" : "=m"(*result) : : "memory");
}
