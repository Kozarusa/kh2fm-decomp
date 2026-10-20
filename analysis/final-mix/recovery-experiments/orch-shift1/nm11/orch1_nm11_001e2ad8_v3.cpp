#include "../common/types.h"
extern "C" u32 func_002fdfc8(...);

extern "C" u8 D_0036e978[];
extern "C" u8 D_0036e998[];
extern "C" u8 D_0036e9b0[];

void func_001e2ad8(s32 first, s32 second, s32 third, s32 fourth) {
    func_002fdfc8(D_0036e978, first);
    asm("" : "+r"(second)); // why: keeps second in its own register so the a1/a2 argument moves follow the original order
    func_002fdfc8(D_0036e998, second, third);
    func_002fdfc8(D_0036e9b0, fourth);
    __builtin_trap();
}
