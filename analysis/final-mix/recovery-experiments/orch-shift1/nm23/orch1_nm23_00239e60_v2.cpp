#include "../common/types.h"
extern "C" f32 D_003714bc;
void func_00239e60(u8* object, f32 x, f32 y, f32 z) {
    f32* pointer = &D_003714bc;
    asm("" : "+r"(pointer)); // why: materialize original full global address before load
    *(f32*)(object + 308) = x;
    *(volatile f32*)(object + 312) = y;
    f32 zero = *pointer;
    s32 flag = 0;
    *(f32*)(object + 316) = z;
    if (x != zero || y != zero || z != zero) flag = 1;
    *(u32*)(object + 184) = (*(u32*)(object + 184) & ~2u) | (flag << 1);
}