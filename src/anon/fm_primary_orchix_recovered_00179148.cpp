#include "../common/types.h"
extern "C" u32 func_0019c090(...);
extern "C" u64 func_001b9d40(...);
extern "C" s32 func_001791e8(u8* object, u8* data);

s32 func_00179148(u8* object) {
    s32 blocked = 0;
    s32 result;
    if (func_0019c090(object) == 0) {
        s32 hit = 0;
        if (*(u32*)(*(u8**)(object + 12) + 8) & 2) {
            goto set;
        }
        if (*(u32*)(object + 0x160) & 0x40) {
        set:
            hit = 1;
        }
        if (!(u8)hit) {
            goto test;
        }
    }
    blocked = 1;
test:
    if ((blocked ^ 1) != 0) {
        if (func_001b9d40(object) != 0) {
            result = func_001791e8(object, object + 16);
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    return result;
}
