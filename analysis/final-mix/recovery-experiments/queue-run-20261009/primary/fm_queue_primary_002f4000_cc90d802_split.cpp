#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };
// Keep the last column store available for the compiler return delay slot.
void func_002f4000(VUMatrix* matrix)
{
 asm volatile("vsub.xyzw $vf4,$vf0,$vf0; vadd.w $vf4,$vf4,$vf0; vmr32.xyzw $vf5,$vf4; vmr32.xyzw $vf6,$vf5; vmr32.xyzw $vf7,$vf6; sqc2 $vf4,48(%0); sqc2 $vf5,32(%0); sqc2 $vf6,16(%0);" : : "r"(matrix) : "memory");
 asm("sqc2 $vf7,%0" : "=m"(matrix->columns[0]) : : "memory");
}
