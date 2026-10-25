#include "../common/types.h"
extern "C" s8 D_0036da98[];
extern "C" s32 func_00168b88(s32, u32, s32, s32);
extern "C" void func_001bdb70(u8*, s32, s32, s32, u8*);

void func_001b5708(u8* object, s32 command) {
    s8* bytes;
    s32 entry;
    s32 handle;
    s32 first;
    s32 second;

    bytes = D_0036da98;
    entry = func_00168b88(*(s32*)(object + 4), 24,
                          bytes[0] | (bytes[2] << 16) | ((bytes[3] << 24) | (bytes[1] << 8)), 0);
    handle = *(s32*)(object + 4);
    first = *(s32*)(entry + 8);
    second = *(s32*)(func_00168b88(handle, 25,
                                   bytes[0] | (bytes[2] << 16) | ((bytes[3] << 24) | (bytes[1] << 8)), 0) + 8);
    func_001bdb70(*(u8**)(*(u8**)(object + 0xc) + 0xb44), command, first, second, 0);
    *(u32*)(object + 0x40) = *(u32*)(object + 0x40) | 8;
    *(s32*)(object + 0x3c) = *(s32*)(object + 0x3c) + 1;
}
