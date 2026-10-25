#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Matrix { kn::FVector rows[4]; };
extern "C" void func_0011b6a8(void*);
extern "C" Matrix* func_0011b7b0(Matrix*, void*);

Matrix* func_0017d8c0(Matrix* matrix, kn::FVector* rotation, kn::FVector* translation) {
    kn::FVector* row = &matrix->rows[3];
    func_0011b6a8(matrix);
    func_0011b7b0(matrix, rotation);
    *row = *translation;

    // FVector members are u32, so the constant is stored through an f32 view of w (swc1); a plain assignment converts float to u32
    *(f32*)&row->w = 1.0f;
    return matrix;
}
