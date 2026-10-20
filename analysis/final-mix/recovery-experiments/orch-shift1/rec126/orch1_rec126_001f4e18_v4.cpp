#include "../common/types.h"
extern "C" u32 func_002223e0(void*);

void func_001f4e18(u8* object, u8* other) {
    u8* base = object + **(s32**)(other + 12);
    u8* first = base + 0xa0;
    u8* second = base + 0xb0;
    func_002223e0(first); // why: volatile second-group stores keep order
    *(s32*)(first + 0x6c) = 0;
    *(u64*)(first + 0x70) = 0;
    *(u64*)(first + 0x78) = 0;
    *(u64*)(first + 0x80) = 0;
    *(u64*)(first + 0x88) = 0;
    *(volatile s32*)(second + 0x2c) = 0;
    *(volatile s32*)(second + 0xc) = 0;
    *(volatile s32*)(second + 0x24) = 0;
}