#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };
// Preserve VU ACC fused matrix/vector operations, including the w lane.

void func_002f3cd8(VUVector* result,const VUMatrix* matrix,const VUVector* vector)
{
 asm volatile("lqc2 $vf4,0(%1); lqc2 $vf5,16(%1); lqc2 $vf6,32(%1); lqc2 $vf7,48(%1); lqc2 $vf8,0(%2); vmulax.xyzw ACC,$vf4,$vf8x; vmadday.xyzw ACC,$vf5,$vf8y; vmaddaz.xyzw ACC,$vf6,$vf8z; vmaddw.xyzw $vf9,$vf7,$vf8w; sqc2 $vf9,%0" : "=m"(*result) : "r"(matrix),"r"(vector) : "memory");
}
