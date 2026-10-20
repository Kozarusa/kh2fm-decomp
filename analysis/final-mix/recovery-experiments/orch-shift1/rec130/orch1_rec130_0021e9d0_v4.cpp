#include "../common/types.h"

extern "C" u8 D_00359a20[];
extern "C" f32 D_00370b48;

void func_0021e9d0(volatile f32* matrix, u32 angle) // why: keeps store order
{
    f32 sine = *(f32*)(D_00359a20 + ((angle >> 2) & 0x3ffc));
    f32 cosine = *(f32*)(D_00359a20 + (((angle + 0x4000) >> 2) & 0x3ffc));
    f32 one = D_00370b48;
    matrix[6] = sine;
    matrix[15] = one;
    matrix[9] = -sine;
    matrix[10] = cosine;
    matrix[0] = one;
    matrix[4] = 0;
    matrix[8] = 0;
    matrix[12] = 0;
    matrix[1] = 0;
    matrix[5] = cosine;
    matrix[13] = 0;
    matrix[2] = 0;
    matrix[14] = 0;
    matrix[3] = 0;
    matrix[7] = 0;
    matrix[11] = 0;
}
