#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Matrix { Quad rows[4]; };
extern "C" void func_0011b6a8(void*);
extern "C" Matrix* func_0011b7b0(Matrix*, void*);

Matrix* func_001604f8(u8* object) {
    Matrix* matrix = (Matrix*)(object + 16);
    func_0011b6a8(matrix);
    Matrix* result = func_0011b7b0(matrix, object + 96);
    if (matrix != result) {
        // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted fm_fallback_vector/fm_copy_helpers; plain Quad copy interleaved (v2)
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(matrix), "r"(result) : "$8", "$9", "$10", "$11", "memory");
    }
    // why: VU macro vector add on the translation row, vadd pattern from accepted fm_fallback_vector/00140500
    asm volatile("lqc2 $vf1,48(%0); lqc2 $vf2,0(%1); vadd.xyz $vf1,$vf1,$vf2; sqc2 $vf1,48(%0)"
                 : : "r"(matrix), "r"(object + 80) : "memory");
    // why: VU macro row scale by vector lanes, broadcast vmul pattern from accepted 00159d30/001c6400
    asm volatile("lqc2 $vf4,0(%1); lqc2 $vf1,0(%0); lqc2 $vf2,16(%0); lqc2 $vf3,32(%0); vmulx.xyzw $vf1,$vf1,$vf4x; vmuly.xyzw $vf2,$vf2,$vf4y; vmulz.xyzw $vf3,$vf3,$vf4z; sqc2 $vf1,0(%0); sqc2 $vf2,16(%0); sqc2 $vf3,32(%0)"
                 : : "r"(matrix), "r"(object + 112) : "memory");
    return result;
}
