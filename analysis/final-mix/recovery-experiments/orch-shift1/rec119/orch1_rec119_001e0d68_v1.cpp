#include "../common/types.h"
extern "C" volatile s32 D_00352bd0;

void func_001e0d68(volatile s32* object, f32* vec) {
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x20) = vec[0];
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x24) = vec[1];
    *(f32*)(*(volatile s32*)(D_00352bd0 + 0xdc4) + object[8] * 0x40 + 0x28) = vec[2];
}
