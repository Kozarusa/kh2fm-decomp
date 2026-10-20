#include "../common/types.h"
extern "C" s32 D_0035f4d0;
extern "C" s32* D_0035f4d4;
s32 func_00292a90(s32 value) {
    s32 index = 0;
    s32 count = D_0035f4d0;
    if (count > 0) {
        s32* cursor = D_0035f4d4;
        do {
            u8 flag = cursor[1] & 1;
            if (flag != 0) {
                if (*cursor == value) return 1;
            }
            ++index;
            cursor += 4;
        } while (index < count);
    }
    return 0;
}
