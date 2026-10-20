#include "../common/types.h"
extern "C" u32 func_002fdfc8(...);
extern "C" u32 func_001e7cc0(...);

extern "C" u8 D_0036e978[];
extern "C" u8 D_0036e998[];
extern "C" u8 D_0036e9c0[];
extern "C" u8 D_0036e9d0[];

u32 func_001e2c00(s32 object) {
    if (object == 0) {
        func_002fdfc8(D_0036e978, D_0036e9c0);
        func_002fdfc8(D_0036e998, D_0036e9d0, 357);
        __builtin_trap();
    }
    return func_001e7cc0(object);
}
