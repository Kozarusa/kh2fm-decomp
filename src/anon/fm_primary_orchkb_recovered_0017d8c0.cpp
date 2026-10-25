#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Matrix { kn::FVector rows[4]; };
extern "C" f32 D_0036c574;
extern "C" void func_0011b6a8(void*);
extern "C" Matrix* func_0011b7b0(Matrix*, void*);

Matrix* func_0017d8c0(Matrix* matrix, kn::FVector* rotation, kn::FVector* translation) {
    kn::FVector* row = &matrix->rows[3];
    func_0011b6a8(matrix);
    func_0011b7b0(matrix, rotation);
    *row = *translation;
    f32* scale = &D_0036c574;
    // why: original forms the D_0036c574 address with lui/addiu t7 and loads with lwc1 $f0,0(t7); without this guard the low half folds into lwc1 $f0,-14988(t7) (108/112 bytes, 9 words)
    asm("" : "+r"(scale));
    // FVector members are u32, so the constant is stored through an f32 view of w (swc1); a plain assignment converts float to u32
    *(f32*)&row->w = *scale;
    return matrix;
}
