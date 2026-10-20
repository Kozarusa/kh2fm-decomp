#include "../common/types.h"
struct __attribute__((aligned(16))) VUVector { f32 x,y,z,w; };
struct __attribute__((aligned(16))) VUMatrix { VUVector columns[4]; };
// Load the left matrix before writes, then multiply each right column with the
// original VU accumulator operations. Pointer updates preserve trapping ADDI.

void func_002f3d08(VUMatrix* result,const VUMatrix* left,const VUMatrix* right)
{
 VUVector* destination=result->columns;
 const VUVector* column=right->columns;
 asm volatile(".set push; .set noreorder; "
              "lqc2 $vf4,0(%2); lqc2 $vf5,16(%2); lqc2 $vf6,32(%2); lqc2 $vf7,48(%2); "
              "addiu $7,$0,4; 1: lqc2 $vf8,0(%1); "
              "vmulax.xyzw ACC,$vf4,$vf8x; vmadday.xyzw ACC,$vf5,$vf8y; "
              "vmaddaz.xyzw ACC,$vf6,$vf8z; vmaddw.xyzw $vf9,$vf7,$vf8w; "
              "sqc2 $vf9,0(%0); addi $7,$7,-1; addi %1,%1,16; "
              "bne $0,$7,1b; addi %0,%0,16; .set pop"
              : "+r"(destination),"+r"(column) : "r"(left) : "$7","memory");
}
