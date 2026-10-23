#include "../common/types.h"
extern "C" u32 D_00348704;
extern "C" s32 func_001991a8(s32, s32);
extern "C" s32 func_0013f030();
extern "C" s32 func_0013f048();
extern "C" s32 func_0013f288();
extern "C" s32 func_0015d690();
extern "C" s32 func_0013f3d0();
extern "C" s32 func_0013f4d8();

s32 func_0013f0d0() {
    s32 result = func_001991a8(0, 0);
    if (result != 0) {
        func_0013f030();
        return func_0013f048();
    }
    switch (D_00348704 & 0x3fffffff) {
    case 1:
        return func_0013f288();
    case 0:
        return func_0015d690();
    case 2:
        return func_0013f3d0();
    case 3:
        return func_0013f4d8();
    }
    return result;
}
