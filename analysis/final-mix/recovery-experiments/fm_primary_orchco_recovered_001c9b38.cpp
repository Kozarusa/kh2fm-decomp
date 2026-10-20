#include "../common/types.h"
extern "C" u32 func_001c99b0(s64);
extern "C" u32 func_001c9ab8(void);

u32 func_001c9b38(u8* object) {
    u32 result;
    switch (*(u16*)(object + 2)) {
    case 4:
        return func_001c99b0(*(s16*)(object + 4));
    case 0x48:
        result = 2;
        if (func_001c9ab8() != 0) {
            result = 0;
        }
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
