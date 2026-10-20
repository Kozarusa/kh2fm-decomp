#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);

void func_001ad020(u8* object, s32 x, s32 y, s32 kind) {
    s32 index = *(s32*)(object + 0xb68);
    // why: original keeps the stride product and the entry pointer in s0
    register s32 offset asm("$16") = index * 0x158;
    u8* entry = object + offset + 0x608;
    *(s32*)(object + 0xb68) = index + 1;
    func_00239bf8((s32)entry, kind + 10);
    *(s32*)(entry + 0x148) = (x - 0x7000) >> 4;
    *(s32*)(entry + 0x14c) = (y - 0x7300) >> 4;
}
