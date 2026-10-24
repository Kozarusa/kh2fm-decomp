// func_0021e9d0: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"

extern "C" u8 D_00359a20[];
extern "C" f32 D_00370b48;

// why: keeps store order

void func_0021e9d0(volatile f32* matrix, u32 angle)
{
    // why: original keeps the sine in $f1 and the unit value in $f2; the volatile read keeps the sine load before the cosine index
    register f32 sine asm("$f1") = *(volatile f32*)(D_00359a20 + ((angle >> 2) & 0x3ffc));
    f32 cosine = *(volatile f32*)(D_00359a20 + (((angle + 0x4000) >> 2) & 0x3ffc)); // why: keeps the cosine load after the sine load
    f32* unit = &D_00370b48;
    asm("" : "+r"(unit)); // why: original forms the full address with addiu and loads at offset 0
    f32 one = *unit;
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
