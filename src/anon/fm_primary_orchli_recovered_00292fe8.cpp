#include "../common/types.h"
extern "C" void func_002ff3fc(u32);
// why: no recovered source calls it; six word arguments derived from a0-a3, t0, t1 (a3 masked to 16 bits before the call), result unused
extern "C" void func_00168410(u32, s32, s32, u16, s32, s32);
extern "C" u8 D_00292e60[];
extern "C" u32 D_0035f4e4;
extern "C" s32* D_0035f4dc;
extern "C" s32 D_0035f4d4;
extern "C" s32 D_0035f4c0;
extern "C" s32 D_0035f4c8;
extern "C" u8 D_0035f4e2;

s32 func_00292fe8() {
    s32 value;
    u32 low;
    s32 high;
    s32 offset;
    func_002ff3fc(D_0035f4e4);
    value = *D_0035f4dc;
    high = value >> 16;
    offset = high * 16;
    low = value & 0xffff;
    *(s32*)(offset + D_0035f4d4) = low;
    *(s32*)(offset + D_0035f4d4 + 4) = 2;
    *(s32*)(offset + D_0035f4d4 + 12) = D_0035f4c8 + high * D_0035f4c0;
    *(s32*)(offset + D_0035f4d4 + 8) = 0;
    func_00168410(D_0035f4e4, *(s32*)(offset + D_0035f4d4 + 12), (s32)(low * D_0035f4c0) / 2048,
                  D_0035f4c0 / 2048, (s32)D_00292e60, offset + D_0035f4d4);
    D_0035f4e2 = 1;
    return 0;
}
