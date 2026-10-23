#include "../common/types.h"
extern "C" s32 D_00347fec;
extern "C" s32 D_00347ff0;
extern "C" s32 D_0033caf4;
extern "C" u8 D_0032bae0;
extern "C" u8 D_003b8ba0[];
extern "C" u8 D_0036acb0[];
extern "C" u8 D_0036acd0[];
extern "C" u8 D_004193c0[];
extern "C" s32 func_00242ea8();
extern "C" s32 func_0014a1f0();
extern "C" s32 func_00242c70();
extern "C" s32 func_00194a08();
extern "C" s32 func_00105ee8(s32);
extern "C" u32 func_002fee78(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_001688c8(...);
extern "C" s32 func_001684c0(u8*, u8*, s32, s32);

s32 func_0013a4c8() {
    if (func_00242ea8() != 0) {
        return 0;
    }
    if (func_0014a1f0() != 0) {
        return 0;
    }
    if (func_00242c70() == 0) {
        if (D_00347fec == 0) {
            return 0;
        }
        D_00347fec = 0;
        D_00347ff0 = -1;
        func_002fee78(D_003b8ba0, D_0036acb0, D_0033caf4);
    } else {
        s32 index = D_0032bae0;
        s32 value = func_00194a08();
        if (index == D_00347fec && value == D_00347ff0) {
            return 0;
        }
        D_00347ff0 = value;
        D_00347fec = index;
        func_002fee78(D_003b8ba0, D_0036acd0, D_0033caf4, func_00105ee8(index), value);
    }
    func_002ff3fc(D_003b8ba0);
    func_001688c8(D_003b8ba0);
    func_001684c0(D_003b8ba0, D_004193c0, 0, 0);
    return 1;
}
