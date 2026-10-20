#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" s32 D_0035f038;
u32 func_00257970() {
    s32 count = 0;
    s32 offset = 0;
    u32 result;
    do {
        s32 object = D_0035f038 + offset;
        offset += 408;
        result = func_00139d78(object + 0x87d0);
        if (result != 0) return result;
        count++;
    } while (count < 24);
    return result;
}


