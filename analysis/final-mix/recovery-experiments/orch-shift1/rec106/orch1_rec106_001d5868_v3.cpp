#include "../common/types.h"
extern "C" s32 func_00181500(u32);
extern "C" s32 func_001a6d08(u32);
extern "C" s32 func_001b8958(u32);

s64 func_001d5868(u16* entry) {
    u32 kind = entry[0];
    if (kind == 2) {
        return func_001b8958(entry[1]);
    }
    if (kind < 3) {
        if (kind == 1) {
            return func_00181500(entry[1]);
        }
    } else if (kind == 3) {
        return func_001a6d08(entry[1]);
    }
    return 0;
}
