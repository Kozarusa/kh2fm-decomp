#include "../common/types.h"
extern "C" s32 D_0034d788[];
extern "C" s32 D_0034d7ac;
extern "C" u8 D_0034d6c0[];
extern "C" s32 D_004f5250;
extern "C" void func_00167658(u8*, s32);

void func_00167f38(s32 index) {
    s32 pointer = (s32)D_0034d6c0;
    D_0034d7ac = D_0034d788[index];
    s32 end = pointer + 0xc0;
    do {
        func_00167658((u8*)pointer, 0xff);
        pointer = pointer + 0x60;
    } while (pointer < end);
    D_004f5250 = index;
}
