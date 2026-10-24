#include "../common/types.h"
#include "../kn/fvector.hpp"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Matrix { Quad rows[4]; };
extern "C" kn::FVector D_01e2bca0;
extern "C" kn::FVector D_01e2bcb0;
extern "C" Matrix D_01e2bcc0;
extern "C" Matrix* func_0017d8c0(Matrix*, kn::FVector*, kn::FVector*);

Matrix* func_002c20f8(kn::FVector* position) {
    D_01e2bca0 = *position;
    Matrix local;
    Matrix* result = func_0017d8c0(&local, &D_01e2bcb0, &D_01e2bca0);
    if (&local != &D_01e2bcc0) {
        // why: 64-byte matrix copy through t0-t3, lq/sq copy primitive as in accepted 001604f8; plain Quad copy interleaved (rec200 v1-v4)
        asm volatile("lq $8,0(%1); lq $9,16(%1); lq $10,32(%1); lq $11,48(%1); sq $8,0(%0); sq $9,16(%0); sq $10,32(%0); sq $11,48(%0)"
                     : : "r"(&D_01e2bcc0), "r"(&local) : "$8", "$9", "$10", "$11", "memory");
    }
    return result;
}
