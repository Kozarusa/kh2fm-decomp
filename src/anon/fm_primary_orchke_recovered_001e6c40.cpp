#include "../common/types.h"
extern "C" u8 D_0036e978[];
extern "C" u8 D_0036ef28[];
extern "C" u8 D_0036e998[];
extern "C" u8 D_0036e9d0[];
extern "C" u8* func_001e3690(u8*);
extern "C" void func_001e8048(u8*, u8*, s32);
extern "C" u32 func_002fdfc8(...);

bool func_001e6c40(u8* object, u32 first, u32 second, u32 third, f32 scale) {
    *(u32*)(object + 136) = first;
    object[147] = second;
    *(u32*)(object + 148) = third;
    *(f32*)(object + 164) = scale;
    *(u32*)(object + 160) = 0;
    u8* data = func_001e3690(object);
    if (data == 0) {
        func_002fdfc8(D_0036e978, D_0036ef28);
        func_002fdfc8(D_0036e998, D_0036e9d0, 0xa03);
        asm volatile("break 0"); // why: original traps with break, __builtin_trap emits teq
        return false;
    }
    func_001e8048(object, data, 1);
    return true;
}
