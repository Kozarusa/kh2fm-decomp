#include "../common/types.h"
extern "C" f32 D_003714c0;
void func_00239eb8(u8* object, f32 x) {
    f32* pointer = &D_003714c0;
    asm("" : "+r"(pointer)); // why: materialize original full global address before load
    *(f32*)(object + 308) = x;
    f32 zero = *pointer;
    s32 flag = 0;
    if (x == zero) {
        if (*(f32*)(object + 312) != zero || *(f32*)(object + 316) != zero) flag = 1;
    } else flag = 1;
    *(u32*)(object + 184) = (*(u32*)(object + 184) & ~2u) | (flag << 1);
}