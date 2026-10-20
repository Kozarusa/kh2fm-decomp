#include "../common/types.h"
extern "C" u32 func_001c99b0(s64);
extern "C" u32 func_001c9ab8(void);

u32 func_001c9b38(u8* object) {
    u16 kind = *(u16*)(object + 2);
    u32 result = 0;
    if (kind == 4) {
        return func_001c99b0(*(s16*)(object + 4));
    }
    if (kind == 0x48) {
        result = func_001c9ab8() == 0 ? 2 : 0;
    }
    return result;
}
