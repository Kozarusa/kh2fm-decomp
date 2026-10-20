#include "../common/types.h"
extern "C" u8* func_0016e920(u32);

u32 func_0016f6f8(u32 id) {
    u32 result;
    if ((id & 0x40000000) != 0) {
        u8* data = func_0016e920(id);
        result = 0;
        if (data != 0) {
            s32 kind = data[4];
            if (kind == 0x16) {
                result = 0;
            } else if (kind < 0x17) {
                result = 0;
                if (kind != 7) {
                    result = 1;
                }
            } else if (kind == 0x18) {
                result = 0;
            } else {
                result = 1;
            }
        }
    } else {
        result = 0;
    }
    return result;
}