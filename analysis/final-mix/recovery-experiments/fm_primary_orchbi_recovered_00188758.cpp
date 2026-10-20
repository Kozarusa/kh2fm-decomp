#include "../common/types.h"
extern "C" bool func_00187e20(...);
extern "C" bool func_00187e58(s32);

u32 func_00188758(s32 object) {
    u32 result = 0;
    if (*(s32*)(object + 0x8c) != 0) {
        u32 word = *(u32*)(object + 0x9c);
        if ((u8)(word & 1) == 0) {
            if (!func_00187e20()) {
                if (*(s32*)(object + 0x98) < 300) {
                    if (!func_00187e58(object)) {
                        result = 1;
                    }
                } else {
                    result = 1;
                }
            }
        }
    }
    return result;
}
