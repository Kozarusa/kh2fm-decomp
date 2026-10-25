#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Matrix { Quad rows[4]; };
extern "C" void func_002e7108(u8*, f32);
extern "C" Matrix* func_002e71a0(Matrix*, u8*, u8, u8);

Matrix* func_002e24e0(u8* object) {
    Matrix* matrix = (Matrix*)(object + 176);
    Matrix local;
    func_002e7108(*(u8**)(object + 108), *(f32*)(object + 260));
    Matrix* result = func_002e71a0(&local, *(u8**)(object + 108), *(u8*)(*(u8**)(object + 100) + 8), 1);
    if (matrix != &local) {
        // why: 64-byte matrix copy through t0-t3 (four lq, then four sq), same primitive text as accepted fm_primary_orchij_recovered_001604f8.cpp; plain Quad copy measured v1 (guard on result) 20 words and v2 (guard on local) 20 words, both interleave lq/sq in other registers
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(matrix), "r"(&local) : "$8", "$9", "$10", "$11", "memory");
    }
    // why: VU macro vector add on the translation row, same text as accepted fm_primary_orchij_recovered_001604f8.cpp
    asm volatile("lqc2 $vf1,48(%0); lqc2 $vf2,0(%1); vadd.xyz $vf1,$vf1,$vf2; sqc2 $vf1,48(%0)"
                 : : "r"(matrix), "r"(object + 240) : "memory");
    return result;
}
