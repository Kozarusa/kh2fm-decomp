#include "../common/types.h"
extern "C" bool func_001c8ab0(void);
extern "C" u32 func_001d6d00(s32);
extern "C" u8 D_0032bb30[];

u32 func_001c8b48(void) {
    u32 result = 0;
    u32 value = func_001d6d00(0x132);
    if (func_001c8ab0()) {
        if (D_0032bb30[13605] == value) {
            result = D_0032bb30[13607] != 0;
        }
    }
    return result;
}
