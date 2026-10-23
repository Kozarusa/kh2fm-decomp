#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Source {
    kn::FVector* rows[4];
    s32 type;
};
extern "C" f32 D_0036b494;

void func_001626e0(Source* source, kn::FVector* matrix) {
    if (source->type == 3) {
        matrix[0] = matrix[3] = matrix[6] = *source->rows[0];
        matrix[1] = matrix[4] = matrix[7] = *source->rows[1];
        matrix[2] = matrix[5] = *source->rows[2];
    } else {
        matrix[0] = matrix[4] = *source->rows[0];
        matrix[1] = matrix[5] = *source->rows[1];
        matrix[2] = matrix[6] = *source->rows[2];
        matrix[3] = matrix[7] = *source->rows[3];
    }
    f32* pointer = &D_0036b494;
    asm("" : "+r"(pointer)); // why: original materializes the full address before lwc1
    f32 one = *pointer;
    ((f32*)&matrix[7])[3] = one;
    ((f32*)&matrix[6])[3] = one;
    ((f32*)&matrix[5])[3] = one;
    ((f32*)&matrix[4])[3] = one;
    ((f32*)&matrix[3])[3] = one;
    ((f32*)&matrix[2])[3] = one;
    ((f32*)&matrix[1])[3] = one;
    ((f32*)&matrix[0])[3] = one;
}
