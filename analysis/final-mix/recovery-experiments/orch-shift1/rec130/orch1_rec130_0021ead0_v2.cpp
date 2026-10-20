#include "../common/types.h"

extern "C" u8 D_00359a20[];
extern "C" u8 D_00370b50[];

void func_0021ead0(volatile f32* matrix, u32 angle) // why: keeps store order
{
    f32 sine = *(volatile f32*)(D_00359a20 + ((angle >> 2) & 0x3ffc)); // why: keeps load order
    f32 cosine = *(volatile f32*)(D_00359a20 + (((angle + 0x4000) >> 2) & 0x3ffc)); // why: keeps load order
    f32 one = *(volatile f32*)D_00370b50; // why: keeps load order
    matrix[1] = sine;
    matrix[15] = one;
    matrix[4] = -sine;
    matrix[5] = cosine;
    matrix[0] = cosine;
    matrix[8] = 0;
    matrix[12] = 0;
    matrix[9] = 0;
    matrix[13] = 0;
    matrix[2] = 0;
    matrix[6] = 0;
    matrix[10] = one;
    matrix[14] = 0;
    matrix[3] = 0;
    matrix[7] = 0;
    matrix[11] = 0;
}
