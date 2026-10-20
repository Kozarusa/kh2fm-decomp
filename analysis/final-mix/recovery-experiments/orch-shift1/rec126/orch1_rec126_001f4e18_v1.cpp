#include "../common/types.h"
extern "C" u32 func_002223e0(void*);

void func_001f4e18(u8* object, u8* other) {
    u8* base = object + **(s32**)(other + 12);
    func_002223e0(base + 0xa0);
    *(s32*)(base + 0x10c) = 0;
    *(u64*)(base + 0x110) = 0;
    *(u64*)(base + 0x118) = 0;
    *(u64*)(base + 0x120) = 0;
    *(u64*)(base + 0x128) = 0;
    *(s32*)(base + 0xdc) = 0;
    *(s32*)(base + 0xbc) = 0;
    *(s32*)(base + 0xd4) = 0;
}