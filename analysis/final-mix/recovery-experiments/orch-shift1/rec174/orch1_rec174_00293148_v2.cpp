#include "../common/types.h"
extern "C" s32 D_0035f4d0;
extern "C" s32* D_0035f4d4;
s32 func_00293148(s32 value) {
    s32 entryCount = D_0035f4d0;
    s32 index = 0;
    if (entryCount > 0) {
        s32 count = entryCount;
        s32* cursor = D_0035f4d4;
        do {
            u8 flag = ((volatile s32*)cursor)[1] & 1;
            if (flag != 0) {
                if (*cursor == value) return cursor[3];
            }
            ++index;
            cursor += 4;
        } while (index < count);
    }
    return 0;
}

