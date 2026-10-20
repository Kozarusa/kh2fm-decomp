#include "../common/types.h"
extern "C" void func_001656d0(u8* object, u32 first, u32 second);
extern "C" u8* D_0034c7a0;

u8* func_001659b8(u32 first, u32 second) {
    u8* pool = D_0034c7a0;
    s32 index = *(s32*)(pool + 0x500) - 1;
    *(s32*)(pool + 0x500) = index;
    u8* entry = pool + index * 4;
    s32 slot = *(s32*)(entry + 0x400);
    u8* object = pool + slot * 16;
    func_001656d0(object, first, second);
    return object;
}
