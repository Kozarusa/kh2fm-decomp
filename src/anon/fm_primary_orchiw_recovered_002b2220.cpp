#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_002b1660(...);
extern "C" s32 D_0035f634;

u32 func_002b2220(void) {
    u32 result;
    s32 count;
    s32 entry;
    s32 offset;
    count = 0;
    offset = 0;
    do {
        entry = D_0035f634 + offset;
        result = func_00139d78((u64)entry);
        offset = offset + 0x198;
        if (result) {
            return result;
        }
        count = count + 1;
    } while (count < 0x30);
    result = func_00139d78(0x4c80 + D_0035f634);
    if (result == 0) {
        offset = 0;
        count = 0;
        do {
            entry = D_0035f634 + offset;
            result = func_00139d78(entry + 0x4e18);
            if (result != 0) {
                return result;
            }
            count = 1 + count;
            offset = 0x198 + offset;
        } while (count < 2);
        result = func_00139d78(0x5148 + D_0035f634);
        if (result == 0 && (result = func_00139d78(0x52e0 + D_0035f634), result == 0) && (result = func_00139d78(0x5610 + D_0035f634), 0 == result) && (result = func_00139d78(0x57c4 + D_0035f634), result == 0) && (result = func_00139d78(D_0035f634 + 0x5e94), 0 == result)) {
            result = func_002b1660();
        }
    }
    return result;
}
