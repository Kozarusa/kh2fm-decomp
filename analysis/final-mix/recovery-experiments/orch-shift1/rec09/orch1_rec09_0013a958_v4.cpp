#include "../common/types.h"
extern "C" s32 D_00347ff8;
extern "C" u8 D_00347ffc;
extern "C" s64 func_001948c0(s64, s64);
extern "C" void func_0013a690();
extern "C" void func_0013a9e8(u32);
extern "C" void func_00170a50();

static inline s64 normalize(s64 value) {
    if (value == 0xffff) {
        value = -1;
    }
    return value;
}

void func_0013a958(u8* pair) {
    s64 found = func_001948c0(normalize(pair[1]), normalize(pair[0])) != 0;
    if (D_00347ff8 == 1 && found == 0) {
        func_0013a690();
        func_0013a9e8(1);
        func_00170a50();
    }
    D_00347ffc = 0;
}
