#include "../common/types.h"
extern "C" u32 func_002fdfc8(...);

extern "C" u8 D_0036e978[];
extern "C" u8 D_0036e998[];
extern "C" u8 D_0036e9b0[];

void func_001e2ad8(s32 first, s32 second, s32 third, s32 fourth) {
    s32 kept_second = second;
    s32 kept_third = third;
    func_002fdfc8(D_0036e978, first);
    func_002fdfc8(D_0036e998, kept_second, kept_third);
    func_002fdfc8(D_0036e9b0, fourth);
    __builtin_trap();
}