#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
// VU accumulation, Q latency and masks retain original three-lane length behavior.
f32 func_002229a0(const VUVector* vector)
{
  VUVector scratch;
  asm volatile("lqc2 $vf10,0(%1); vmul.xyz $vf10,$vf10,$vf10; vmove.xyz $vf9,$vf10; vaddx.y $vf9,$vf9,$vf9x; vaddy.z $vf9,$vf9,$vf9y; vsqrt Q,$vf9z; vwaitq; vaddq.x $vf10,$vf0,Q; sqc2 $vf10,%0"
               : "=m"(scratch) : "r"(vector) : "memory");
  return scratch.x;
}
