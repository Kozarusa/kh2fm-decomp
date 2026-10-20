#include "../common/types.h"
extern "C" u8 D_0036e7a0[];
extern "C" s32 D_0034e948;
extern "C" void func_0017d0e8(void*, f32);
extern "C" s32 func_0019c778(s32, void*);

s32 func_001db250(u8* object) {
    u32 buffer[4];
    func_0017d0e8(buffer, *(f32*)D_0036e7a0 - *(f32*)(*(u8**)(object + 0x6c) + 0x20));
    return func_0019c778(D_0034e948, buffer);
}
