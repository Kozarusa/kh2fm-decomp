#include "../common/types.h"
extern "C" s16 D_00372be0[];
s32 func_002594b8(s32 value) {
    s32 result = -1;
    s32 index = 0;
    if (D_00372be0[0] >= 0) {
        do {
            if (D_00372be0[index * 2] == value) return (u16)D_00372be0[index * 2 + 1];
            index++;
        } while (D_00372be0[index * 2] >= 0);
    }
    return result;
}
