#include "../common/types.h"
extern "C" u8 D_00362d20[];
extern "C" volatile f32 D_00375e30;

f32 func_002dea00(s32* object, f32 first, f32 second) {
    object[1] = 30;
    object[14] = -1;
    object[2] = 256;
    object[0] = (s32)D_00362d20;
    *(f32*)&object[3] = second;
    *(f32*)&object[5] = first;
    // why: keeps all six object stores before the D_00375e30 load; without it the load is hoisted to the top and the stores are reordered (17 words)
    asm volatile("" ::: "memory");
    volatile f32* sourcePointer = &D_00375e30;
    // why: keeps the full lui/addiu address in a register so the load is lwc1 0(t7); without it the low half folds into lwc1 24112(t7) (4 words)
    asm("" : "+r"(sourcePointer));
    f32 result = *sourcePointer;
    *(f32*)&object[4] = result;
    return result;
}
