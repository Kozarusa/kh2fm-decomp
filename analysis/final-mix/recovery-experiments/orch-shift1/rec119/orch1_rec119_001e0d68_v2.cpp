#include "../common/types.h"
extern "C" volatile s32 D_00352bd0;

void func_001e0d68(volatile s32* object, f32* vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x20) = x;
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x24) = y;
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x28) = z;
}
