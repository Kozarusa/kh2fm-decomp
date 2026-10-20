#include "../common/types.h"
extern "C" u32 func_00181500(u32);
extern "C" u32 func_001a6d08(u32);
extern "C" u32 func_001b8958(u32);

u32 func_001d5868(u16* entry) {
    u32 kind = entry[0];
    u32 result;
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
