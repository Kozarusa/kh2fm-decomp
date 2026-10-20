#include "../common/types.h"
extern "C" void func_00177a58(u8*);
extern "C" u32 func_00187018(f32, u64, s32, u64, s64);
extern "C" f32 D_0036c4b0;

void func_00176620(u8* object, s32 second) {
    *(u32*)(object + 0x108) |= 0x2000000;
    func_00177a58(object);
    func_00187018(D_0036c4b0, (u64)object, second, 0, -1);
}
