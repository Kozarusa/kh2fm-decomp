#include "../common/types.h"
extern "C" s32 D_00350448;
extern "C" f32 D_00350464;

void func_0019ee28(s32 flag, s64 id) {
    if (id == 0xffff && flag == 1) {
        f32 zero = 0.0f;
        f32* pointer = (f32*)((u8*)&D_00350448 + 32);
        *pointer = zero;
        D_00350448 = 0;
        D_00350464 = zero;
    }
}
