#include "../common/types.h"
extern "C" void func_002fee78(void*, u8*, s32);
extern "C" void func_00168388(u8*, s32, s32, s32);
extern "C" u8 D_00292e60[];
extern "C" u8 D_00374578[];
extern "C" s32* D_0035f4dc;
extern "C" s32 D_0035f4d4;
extern "C" s32 D_0035f4c0;
extern "C" s32 D_0035f4c8;
extern "C" u8 D_0035f4e2;

s32 func_00292f18() {
    u8 buffer[32];
    s32 value = *D_0035f4dc;
    u32 low = value & 0xffff;
    s32 high = value >> 16;
    s32 offset;
    func_002fee78(buffer, D_00374578, low);
    offset = high * 16;
    *(s32*)(offset + D_0035f4d4) = low;
    *(s32*)(offset + D_0035f4d4 + 4) = 2;
    *(s32*)(offset + D_0035f4d4 + 12) = D_0035f4c8 + high * D_0035f4c0;
    *(s32*)(offset + D_0035f4d4 + 8) = 0;
    func_00168388(buffer, *(s32*)(offset + D_0035f4d4 + 12), (s32)D_00292e60, offset + D_0035f4d4);
    D_0035f4e2 = 1;
    return 0;
}
