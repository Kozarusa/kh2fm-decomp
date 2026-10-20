#include "../common/types.h"
extern "C" s64 func_00181500(u32);
extern "C" s64 func_001a6d08(u32);
extern "C" s64 func_001b8958(u32);

s32 func_001d5868(u16* entry) {
    u32 kind = entry[0];
    s64 result;
    if (kind == 2) {
        result = func_001b8958(entry[1]);
    } else {
        if (kind < 3) {
            if (kind == 1) {
                result = func_00181500(entry[1]);
                return result;
            }
        } else if (kind == 3) {
            result = func_001a6d08(entry[1]);
            return result;
        }
        result = 0;
    }
    return result;
}
