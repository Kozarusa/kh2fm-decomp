#include "../common/types.h"
union FloatBits { u32 bits; f32 value; };
// Preserve five original VU random-state updates and the final float adjustment.
f32 func_00209fb8(void)
{
 register u32 bits asm("$15");
 asm volatile("addi $8,$0,-1; qmtc2 $8,$vf2; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vrxor R,$vf2x; vrnext.x $vf1,R; vitof0.x $vf2,$vf2; vadd.x $vf1,$vf1,$vf2; qmfc2 %0,$vf1" : "=r"(bits) : : "$8","memory");
 FloatBits result; result.bits=bits; return result.value;
}
