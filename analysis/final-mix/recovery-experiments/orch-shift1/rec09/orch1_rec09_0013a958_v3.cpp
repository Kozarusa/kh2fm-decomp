#include "../common/types.h"
extern "C" s32 D_00347ff8;
extern "C" u8 D_00347ffc;
extern "C" s64 func_001948c0(s64, s64);
extern "C" void func_0013a690();
extern "C" void func_0013a9e8(u32);
extern "C" void func_00170a50();

void func_0013a958(u8* pair) {
    s64 second = pair[1];
    if (second == 0xffff) {
        second = -1;
    }
    s64 first = pair[0];
    if (first == 0xffff) {
        first = -1;
    }
    s64 found = func_001948c0(second, first) != 0;
    if (D_00347ff8 == 1 && found == 0) {
        func_0013a690();
        func_0013a9e8(1);
        func_00170a50();
    }
    D_00347ffc = 0;
}


