#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
// Retain VU clamp selection behavior and both original float argument transports.

void func_002f42e8(f32 lower,f32 upper,VUVector* result,const VUVector* source)
{
 asm volatile("mfc1 $8,%2; mfc1 $9,%3; lqc2 $vf6,0(%1); qmtc2 $8,$vf4; qmtc2 $9,$vf5; vmaxx.xyzw $vf6,$vf6,$vf4x; vminix.xyzw $vf6,$vf6,$vf5x; sqc2 $vf6,%0"
              : "=m"(*result) : "r"(source),"f"(lower),"f"(upper) : "$8","$9","memory");
}
