#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };
// The final vector store is separate so the compiler owns return-slot scheduling.
void func_002f3cd8(VUVector* result,const VUMatrix* matrix,const VUVector* vector)
{
 asm volatile("lqc2 $vf4,0(%0); lqc2 $vf5,16(%0); lqc2 $vf6,32(%0); lqc2 $vf7,48(%0); lqc2 $vf8,0(%1); vmulax.xyzw ACC,$vf4,$vf8x; vmadday.xyzw ACC,$vf5,$vf8y; vmaddaz.xyzw ACC,$vf6,$vf8z; vmaddw.xyzw $vf9,$vf7,$vf8w;" : : "r"(matrix),"r"(vector) : "memory");
 asm("sqc2 $vf9,%0" : "=m"(*result) : : "memory");
}
