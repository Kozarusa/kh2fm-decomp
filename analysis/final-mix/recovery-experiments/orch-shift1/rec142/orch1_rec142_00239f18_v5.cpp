#include "../common/types.h"
extern "C" f32 D_003714c4;
void func_00239f18(u8* object, f32 y) {
    f32* pointer = &D_003714c4;
    f32 x = *(f32*)(object + 308);
    asm("" : "+r"(pointer), "+f"(x), "+f"(y)); // why: keep x load before address materialization and y store after
    *(f32*)(object + 312) = y;
    f32 zero = *pointer;
    s32 flag = 0;
    if (x != zero || y != zero || *(f32*)(object + 316) != zero) flag = 1;
    *(u32*)(object + 184) = (*(u32*)(object + 184) & ~2u) | (flag << 1);
}