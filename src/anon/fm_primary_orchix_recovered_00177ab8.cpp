#include "../common/types.h"
extern "C" s32 func_00177860(...);
extern "C" void func_00177a28(u8*);
extern "C" void func_00177a38(u8*);
extern "C" void func_00177a78(u8*);

s32 func_00177ab8(u8* object, u8 flag) {
    u32 state;
    if ((*(u32*)(object + 0x168) & 0x20) && flag) {
        u8 level = object[0xb05];
        if (level < ((u8*)func_00177860())[0x2e]) {
            func_00177a78(object);
            goto clear;
        }
    }
    state = *(u32*)(object + 0x160);
    if ((state & 0x400) && flag) {
        func_00177a38(object);
    } else {
        s32 hit = 0;
        if (state & 4) {
            goto set;
        }
        if (state & 8) {
            goto set;
        }
        if (state & 0x10) {
        set:
            hit = 1;
        }
        if (!(u8)hit) {
            return 0;
        }
        func_00177a28(object);
    }
clear:
    *(u32*)(object + 0x108) &= 0xfdffffff;
    return 1;
}
