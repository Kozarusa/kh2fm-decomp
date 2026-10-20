#include "../common/types.h"

extern "C" u8 D_00359a20[];
extern "C" f32 D_00370b4c;

void func_0021ea50(volatile f32* matrix, u32 angle) // why: keeps store order
{
    f32 sine = *(volatile f32*)(D_00359a20 + ((angle >> 2) & 0x3ffc)); // why: keeps load order
    f32 cosine = *(volatile f32*)(D_00359a20 + (((angle + 0x4000) >> 2) & 0x3ffc)); // why: keeps load order
    f32 one = D_00370b4c;
    matrix[10] = cosine;
    matrix[15] = one;
    matrix[2] = -sine;
    matrix[0] = cosine;
    matrix[4] = 0;
    matrix[8] = sine;
    matrix[12] = 0;
    matrix[1] = 0;
    matrix[5] = one;
    matrix[9] = 0;
    matrix[13] = 0;
    matrix[6] = 0;
    matrix[14] = 0;
    matrix[3] = 0;
    matrix[7] = 0;
    matrix[11] = 0;
}
