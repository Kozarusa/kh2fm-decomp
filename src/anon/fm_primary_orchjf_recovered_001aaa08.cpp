#include "../common/types.h"
extern "C" u8 D_01c6cc60[];
extern "C" u8* D_00350a28;
extern "C" s32 D_0033caf4;
extern "C" s8 D_0036d740[];
extern "C" s8 D_0036d748[];
extern "C" s8 D_0036d750[];
extern "C" u32 D_01c6cec4;
extern "C" u32 D_01c6cec0;
extern "C" s32 D_00350a30;
extern "C" void func_001aabd8();
extern "C" void func_002fee78(void*, u8*, s32);
extern "C" s32 func_001b1490(void*);
extern "C" s32 func_00168b88(s32, u32, s32, s32);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_00105c30(void);

u32 func_001aaa08() {
    u8 buffer[48];
    u8* table = D_01c6cc60;
    s32 object;
    s32 entry;
    u32 first;
    u32 second;
    u32 region;
    s32 flag;
    func_001aabd8();
    flag = 0;
    func_002fee78(buffer, D_00350a28, D_0033caf4);
    object = func_001b1490(buffer);
    entry = func_00168b88(object, 2, D_0036d740[0] | (D_0036d740[2] << 16) | ((D_0036d740[3] << 24) | (D_0036d740[1] << 8)), 0);
    first = *(u32*)(entry + 8);
    *(u32*)(table + 188) = first;
    *(u32*)(table + 92) = first;
    *(u32*)(table + 60) = first;
    *(u32*)(table + 28) = first;
    entry = func_00168b88(object, 2, D_0036d748[0] | (D_0036d748[2] << 16) | ((D_0036d748[3] << 24) | (D_0036d748[1] << 8)), 0);
    second = *(u32*)(entry + 8);
    *(u32*)(table + 156) = second;
    *(u32*)(table + 124) = second;
    entry = func_00168b88(object, 2, D_0036d750[0] | (D_0036d750[2] << 16) | ((D_0036d750[3] << 24) | (D_0036d750[1] << 8)), 0);
    D_01c6cec4 = *(u32*)(entry + 8);
    entry = func_00168b38(object, 25, 0);
    D_01c6cec0 = *(u32*)(entry + 8);
    if ((region = func_00105c30()) == 1 || (region = func_00105c30()) == 8) {
        flag = 1;
    }
    if ((flag & 0xff) == 0) {
        u8* bytes = D_01c6cc60;
        bytes[179] = 24;
        bytes[83] = 24;
        bytes[51] = 24;
        bytes[19] = 24;
        bytes[147] = 32;
        bytes[115] = 32;
        D_00350a30 = 32;
    }
    return region;
}
