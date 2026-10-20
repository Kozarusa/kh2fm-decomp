#include "../common/types.h"
extern "C" f32 D_00350990[4];
extern "C" void func_001024a8(u32);

void func_001733f8(s32 object) {
    s32 count = *(s32*)(object + 4);
    *(s32*)(object + 4) = count - 1;
    if (count <= 0) {
        D_00350990[0] = *(f32*)(object + 8);
        D_00350990[1] = *(f32*)(object + 12);
        D_00350990[2] = *(f32*)(object + 16);
        *(s32*)&D_00350990[3] = 0;
        func_001024a8(object);
    }
}