#include "../common/types.h"
extern "C" u32 D_0034f240;
extern "C" bool func_0019ba60(...);
extern "C" u32 func_001ba158(...);

s32 func_001a2200(u8* object, s32 value) {
    if (value > 0 && (D_0034f240 & 0x20000) != 0) {
        s32 count = *(s32*)(func_001ba158() + 8) + 1;
        if (count > 1) {
            if (!func_0019ba60(*(u8**)(object + 0x25c))) {
                value = value * count;
            } else if ((*(u32*)(*(u8**)(object + 0x25c) + 0x588) & 0x80) != 0) {
                value = value / count;
                if (value < 1) {
                    value = 1;
                }
            } else {
                value = value * count;
            }
        }
    }
    return value;
}
