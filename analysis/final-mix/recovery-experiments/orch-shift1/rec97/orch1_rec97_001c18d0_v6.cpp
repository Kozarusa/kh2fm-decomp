#include "../common/types.h"

u32 func_001c18d0(u8* object) {
    s64 ok = ((s64 (*)())*(u32*)(object + 0x10))();
    u32 result = 0;
    if (ok != 0) {
        u8* data = *(u8**)(object + 0x20);
        result = 1;
        if (data != 0) {
            s32 kind = *(s32*)(*(u8**)(object + 0x1c) + 4);
            if (kind == 0) {
                result = data[0xf];
            } else if (kind == 1) {
                result = data[0xd];
            } else {
                result = 0;
            }
            object[0x17] = result;
            result = 1;
        }
    }
    return result;
}