#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
union FloatBits { u32 bits; f32 value; };
// VU Q and lane-masked arithmetic retain the original macro-mode operations.

f32 func_002229d8(const VUVector* vector)
{
  register u32 bits asm("$2");
  asm volatile("lqc2 $vf10,0(%1); vmul.xy $vf10,$vf10,$vf10; vaddx.y $vf10,$vf10,$vf10x; vsqrt Q,$vf10y; vwaitq; cfc2 %0,$22"
               : "=r"(bits) : "r"(vector) : "memory");
  FloatBits result; result.bits=bits; asm volatile("nop" : "+f"(result.value)); return result.value;
}
