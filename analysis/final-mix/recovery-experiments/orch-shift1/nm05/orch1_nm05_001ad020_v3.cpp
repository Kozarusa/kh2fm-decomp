#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);

void func_001ad020(u8* object, s32 x, s32 y, s32 kind) {
    s32 index = *(s32*)(object + 0xb68);
    // why: one variable holds the constant, the product and the entry so they share a saved register
    s32 entry = 0x158;
    entry = index * entry;
    entry = (s32)object + entry + 0x608;
    *(s32*)(object + 0xb68) = index + 1;
    func_00239bf8(entry, kind + 10);
    *(s32*)(entry + 0x148) = (x - 0x7000) >> 4;
    *(s32*)(entry + 0x14c) = (y - 0x7300) >> 4;
}
