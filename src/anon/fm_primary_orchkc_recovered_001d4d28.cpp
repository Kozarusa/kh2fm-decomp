#include "../common/types.h"
extern "C" void func_001d1678(u8*, s32);
extern "C" void func_001d19e8(u8*, s32);
extern "C" void func_001d16e8(u8*, s32, s32);
// why: no accepted call site; the accepted tiny.cpp definition (u32,u32,u32,u32) marks a1-a3 unused, and passing them adds three argument moves (v1, 160/148 bytes); the original sets only a0, so the parameter is derived from registers
extern "C" void func_00320400(u8*);
extern "C" u8 D_003525c8[];
extern "C" u8 D_00352750[];

void func_001d4d28(u8* object) {
    s32 index;
    *(s32*)(object + 4) = 0;
    // why: an integer-typed first table store keeps it ordered with the integer zero stores, matching the original prologue interleave (u8** store v2/v3 scheduled sd s0 first, 4 words)
    *(u32*)object = (u32)D_003525c8;
    *(s32*)(object + 8) = 0;
    func_00320400(object + 12);
    func_001d1678(object, -1);
    *(s32*)(object + 0x30) = 0;
    *(u8**)object = D_00352750;
    for (index = 0; index < 128; index++) {
        object[0x39 + index * 4] = 0;
    }
    func_001d19e8(object, -1);
    func_001d16e8(object, 0, 12);
}
