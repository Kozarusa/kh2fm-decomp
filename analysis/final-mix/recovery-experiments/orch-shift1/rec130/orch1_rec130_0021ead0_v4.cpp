#include "../common/types.h"

extern "C" u8 D_00359a20[];
extern "C" u8 D_00370b50[];

void func_0021ead0(volatile f32* matrix, u32 angle) // why: keeps store order
{
    u32 sineindex = (angle >> 2) & 0x3ffc; // why: keeps load order
    u32 cosineindex = ((angle + 0x4000) >> 2) & 0x3ffc; // why: keeps load order
    f32 sine = *(volatile f32*)(D_00359a20 + sineindex); // why: keeps load order
    f32 cosine = *(volatile f32*)(D_00359a20 + cosineindex); // why: keeps load order
    f32 one = *(f32*)D_00370b50;
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
