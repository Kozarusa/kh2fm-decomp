#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 D_0035f5b0;

u32 func_0029ad40(void) {
    u32 result;
    s32 entry;
    u32 offset;
    s32 count;
    result = func_00139d78(D_0035f5b0);
    if ((((0 == result) && (result = func_00139d78(D_0035f5b0 + 0x1b4), result == 0)) && (result = func_00139d78(D_0035f5b0 + 0x368), 0 == result)) && (result = func_00139d78(0x51c + D_0035f5b0), result == 0)) {
        count = 0;
        offset = 0;
        do {
            result = func_00139d78(D_0035f5b0 + offset + 0x6d0);
            if (result != 0) {
                return result;
            }
            entry = D_0035f5b0 + offset;
            result = func_00139d78(entry + 0xf54);
            offset += 0x1b4;
            if (result != 0) {
                return result;
            }
            count = count + 1;
        } while (count < 5);
        result = func_00139d78(D_0035f5b0 + 0x17d8);
        if (result == 0) {
            result = func_00139d78(D_0035f5b0 + 0x1970);
        }
    }
    return result;
}
