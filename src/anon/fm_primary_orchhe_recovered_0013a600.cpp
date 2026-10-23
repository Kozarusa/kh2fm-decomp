#include "../common/types.h"
extern "C" u8 D_0032bae0;
extern "C" u32 D_00347fe8;
extern "C" s32 D_0033caf4;
extern "C" u8 D_003b8b80[];
extern "C" u8 D_0036acf0[];
extern "C" u8 D_003b8bc0[];
extern "C" u32 func_00105ee8(u32);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_001688c8(...);
extern "C" u32 func_001684c0(u8*, u8*, s32, s32);

void func_0013a600() {
    u32 value = D_0032bae0;
    if (value == D_00347fe8) {
        return;
    }
    D_00347fe8 = value;
    func_002fee78(D_003b8b80, D_0036acf0, D_0033caf4, func_00105ee8(value));
    func_001688c8(D_003b8b80);
    func_001684c0(D_003b8b80, D_003b8bc0, 0, 0);
}
