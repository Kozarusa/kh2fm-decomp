#include "../common/types.h"
extern "C" s32* D_0035f630;
extern "C" u32 func_00287bc0(void);

// why: every exit leaves the function's own constant or flag in v0, so the return is s32
s32 func_002b3b78(s32 slot) {
    s32 result = 0;
    if (slot < 0) {
        return 1;
    }
    switch (func_00287bc0()) {
    case 28: {
        s32 found = 0;
        s32 index = 0;
        s32* entry = D_0035f630;
        do {
            s32 value = *entry;
            if (value & 0x1000000) {
                if (found == slot) {
                    result = (value >> 25) & 1;
                    break;
                }
                found++;
            }
            index++;
            entry += 9;
        } while (index < 10);
        break;
    }
    case 27:
    case 30:
        result = 1;
        break;
    case 29:
    case 31:
    case 32:
    case 33:
        result = 0;
        break;
    }
    return result;
}
