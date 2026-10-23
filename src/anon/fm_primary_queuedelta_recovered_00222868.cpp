#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
// Normalize x/y using original VU scratch lanes and explicit Q waits.
// The other output lanes retain the original vf31 scratch contents.

void func_00222868(VUVector* result,const VUVector* source)
{
 asm volatile("lqc2 $vf1,0(%1); vmul.xy $vf31,$vf1,$vf1; vaddy.x $vf31,$vf31,$vf31y; vsqrt Q,$vf31x; vwaitq; vaddq.x $vf31,$vf0,Q; vdiv Q,$vf0w,$vf31x; vwaitq; vmulq.xy $vf31,$vf1,Q; sqc2 $vf31,%0; nop"
              : "=m"(*result) : "r"(source) : "memory");
}
