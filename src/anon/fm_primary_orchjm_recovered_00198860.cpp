#include "../common/types.h"
extern "C" s8 D_0036d0c8[];
extern "C" u8* D_0034e948;
extern "C" void func_00198970(u8*);
extern "C" s32 func_00168b88(s32, u32, s32, s32);
extern "C" void func_001bdb70(u8*, s32, s32, s32, u8*);
extern "C" s32 func_0019d720(u8*);

// Preserve original registry aliases.
s32 func_00198860(u8* object, s32 command) asm("_ZN2YS6STDOBJ19set_special_commandEi");

s32 func_00198860(u8* object, s32 command) {
    s8* bytes;
    u8* list;
    s32 entry;
    s32 handle;
    s32 first;
    s32 second;
    u8* target;
    s32 result;

    func_00198970(object);
    bytes = D_0036d0c8;
    list = object + 0x7a0;
    entry = func_00168b88(*(s32*)(list + 0x10), 24,
                          bytes[0] | (bytes[2] << 16) | ((bytes[3] << 24) | (bytes[1] << 8)), 0);
    handle = *(s32*)(list + 0x10);
    first = *(s32*)(entry + 8);
    second = *(s32*)(func_00168b88(handle, 25,
                                   bytes[0] | (bytes[2] << 16) | ((bytes[3] << 24) | (bytes[1] << 8)), 0) + 8);
    target = *(u8**)(D_0034e948 + 0xb44);
    func_001bdb70(target, command, first, second, object);
    result = func_0019d720(target + 0x9f8);
    *(u32*)(object + 0x10c) = *(u32*)(object + 0x10c) | 0x800;
    *(s32*)(object + 0x488) = *(s32*)(object + 0x488) + 1;
    return result;
}
