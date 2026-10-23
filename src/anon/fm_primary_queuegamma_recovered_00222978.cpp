#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
union FloatBits { u32 bits; f32 value; };
// Only the y lane is consumed by VSQRT; other scratch lanes stay unspecified.

f32 func_00222978(f32 value)
{
  VUVector scratch; scratch.y=value;
  register u32 bits asm("$2");
  asm volatile("lqc2 $vf10,%1; vsqrt Q,$vf10y; vwaitq; cfc2 %0,$22"
               : "=r"(bits) : "m"(scratch) : "memory");
  FloatBits result; result.bits=bits; return result.value;
}
