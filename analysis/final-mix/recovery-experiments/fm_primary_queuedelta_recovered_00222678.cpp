#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
// Preserve VU MAX selection semantics and the two original float argument lanes.

f32 func_00222678(f32 first,f32 second)
{
  VUVector scratch; scratch.x=first; scratch.y=second;
  asm volatile("lqc2 $vf1,%0; vmaxy.x $vf1,$vf1,$vf1y; sqc2 $vf1,%0"
               : "+m"(scratch) : : "memory");
  return scratch.x;
}
