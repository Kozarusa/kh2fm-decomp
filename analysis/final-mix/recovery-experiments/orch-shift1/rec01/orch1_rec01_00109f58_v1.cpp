#include "../common/types.h"

u64 func_00109f58(u32 kind, s32 flag, u8 value) {
    switch (kind) {
    case 7:
    case 11:
        if (flag == 0) {
            return 0x8000000044ULL;
        }
    case 1:
    case 3:
    case 5: {
        u64 result = 0x8000000044ULL;
        if (value == 0x80) {
            result = 42;
        }
        return result;
    }
    case 2:
    case 4:
    case 8:
        return 0x8000000044ULL;
    default:
        return 0x44;
    }
}
