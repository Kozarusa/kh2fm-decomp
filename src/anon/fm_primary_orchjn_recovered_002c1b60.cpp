#include "../common/types.h"
extern "C" u32 func_002c1cb0(void*, s64);

u32 func_002c1b60(u8* object, u8* entry) {
    register u32 flags asm("$15"); // why: original keeps the flags word in t7
    register u32 mask asm("$13"); // why: original holds the second mask in t5
    if (*entry == 1) goto clear;
    if (*entry != 2) goto setbits;
clear:
    flags = *(u32*)(object + 264);
    mask = ~0x20;
    flags = flags & ~2;
    flags = flags & mask;
    flags = flags & ~0x40;
    goto store;
setbits:
    flags = *(u32*)(object + 264) | 0x62;
store:
    *(u32*)(object + 264) = flags;
    u32 result = func_002c1cb0(*(void**)(object + 2788), *entry);
    *(u8*)(object + 2792) = *entry;
    return result;
}
