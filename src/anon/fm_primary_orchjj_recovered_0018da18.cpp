#include "../common/types.h"
extern "C" u32 func_0018c8f0(...);
extern "C" u32 func_00198580(...);
extern "C" u32 func_001de2e0(...);
extern "C" u32 func_001877a0(...);

u32 func_0018da18(u8* object, u8* owner, u8* entry) {
    u32 result = func_0018c8f0(object, entry, owner);
    u8* child = *(u8**)(object + 0xc);
    if (child != 0) {
        *(u32*)(child + 0x108) |= 0x2000000;
    }
    *(u32*)(object + 4) |= 2;
    if (*(u32*)(result + 0x18) & 4) {
        return result;
    }
    u32* flags = (u32*)(owner + 0xabc);
    if (((flags[0] | flags[1]) & ~flags[2]) & 0x2000) {
        return result;
    }
    if (*(s32*)(entry + 0x1c) >= 0) {
        func_00198580(*(u32*)(object + 0x10), *(s32*)(entry + 0x1c));
    }
    s32* pointer = *(s32**)(object + 0x24);
    if (pointer == 0) {
        return result;
    }
    if (*pointer == 0) {
        return result;
    }
    u8 count = entry[0xb];
    if (count == 0) {
        return result;
    }
    u64 bit = ((u64)1 << 32) << (count - 1);
    u64 mask;
    if (*(u32*)(owner + 0x588) & 0x80) {
        mask = bit | 0x400;
    } else {
        mask = bit | 0x800;
    }
    s32 index = func_001de2e0(pointer, mask);
    if (index >= 0) {
        func_001877a0(owner, *(u32*)(object + 0x24), index);
    }
    return result;
}
