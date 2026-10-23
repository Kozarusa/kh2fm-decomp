#include "../common/types.h"
extern "C" u32 func_00170b30(...);
extern "C" s32 func_00106178(u8*, s32);
extern "C" void func_00103bb0(s32);
extern "C" s32 func_00103590(s32, s32);
extern "C" s32 D_003638c4;
extern "C" u8 D_003638c0;
extern "C" u8 D_003638c8;

s32 func_002ef6b0() {
    func_00103bb0(5);
    u8* allocation = (u8*)func_00170b30(0xa0000);
    s32 value = func_00106178(allocation, 0xa0000);
    D_003638c4 = value;
    s32 result = func_00103590(1, value);
    D_003638c0 = 0;
    D_003638c8 = 0;
    return result;
}
