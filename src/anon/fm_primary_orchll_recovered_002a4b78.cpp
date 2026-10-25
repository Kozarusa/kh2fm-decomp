#include "../common/types.h"
extern "C" s32 D_0035f5e4;
extern "C" u32 func_00276568(void);
extern "C" u32 func_00287bc0(void);

// why: both exits leave a direct callee v0 (00287bc0 or 00276568), so the last-computed result is returned

u32 func_002a4b78(void) {
    u32 result = func_00287bc0();
    if (result == 26 || result == 34 || result == 33) {
        *(s32*)(D_0035f5e4 + 0x1084) = 0;
        *(s32*)(D_0035f5e4 + 0x1088) = 0;
        return result;
    }
    s32 limit = *(s32*)(D_0035f5e4 + 0x1080);
    if (limit >= 10) {
        limit = 9;
    }
    result = func_00276568();
    s32 count = *(s8*)result;
    s32 total = 0;
    if (count > 0) {
        u8* entry = (u8*)(D_0035f5e4 + 0x1001);
        s32 left = count;
        do {
            left--;
            total += *entry;
            entry += 8;
        } while (left != 0);
    }
    s32 value = *(s32*)(D_0035f5e4 + 0x1080) - limit;
    if (!(value < total)) {
        *(s32*)(D_0035f5e4 + 0x1084) = total;
        *(s32*)(D_0035f5e4 + 0x1088) = 0;
    } else {
        *(s32*)(D_0035f5e4 + 0x1084) = value;
        *(s32*)(D_0035f5e4 + 0x1088) = (total - *(s32*)(D_0035f5e4 + 0x1084)) * 8;
    }
    return result;
}
