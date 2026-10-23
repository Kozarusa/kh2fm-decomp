#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };
// Preserve perspective division and original lane-specific fixed-point conversions.

void func_002f47d8(VUVector* result,const VUMatrix* matrix,const VUVector* vector,s32 integralZW)
{
 asm volatile("lqc2 $vf4,0(%0); lqc2 $vf5,16(%0); lqc2 $vf6,32(%0); lqc2 $vf7,48(%0); lqc2 $vf8,0(%1); vmulax.xyzw ACC,$vf4,$vf8x; vmadday.xyzw ACC,$vf5,$vf8y; vmaddaz.xyzw ACC,$vf6,$vf8z; vmaddw.xyzw $vf9,$vf7,$vf8w; vdiv Q,$vf0w,$vf9w; vwaitq; vmulq.xyz $vf9,$vf9,Q; vftoi4.xyzw $vf10,$vf9"
              : : "r"(matrix),"r"(vector) : "memory");
 if(integralZW!=0) asm volatile("vftoi0.zw $vf10,$vf9" : : : "memory");
 asm("sqc2 $vf10,%0" : "=m"(*result) : : "memory");
}
