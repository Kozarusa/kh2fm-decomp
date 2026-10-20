#include "../common/types.h"
extern "C" f32 D_0036e7a0;
extern "C" s32 D_0034e948;
extern "C" void func_0017d0e8(void*, f32);
extern "C" s32 func_0019c778(s32, void*);

s32 func_001db250(u8* object) {
    u32 buffer[4];
    u8* inner = *(u8**)(object + 0x6c);
    f32 angle = *(f32*)(inner + 0x20);
    f32 base = D_0036e7a0;
    func_0017d0e8(buffer, base - angle);
    return func_0019c778(D_0034e948, buffer);
}
