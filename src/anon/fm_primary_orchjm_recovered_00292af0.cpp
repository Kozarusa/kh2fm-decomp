#include "../common/types.h"
extern "C" s16 D_0035f4e0;
extern "C" u16* D_0035f4dc;

s32 func_00292af0(s32 value) {
    s32 found = 0;
    s32 index;
    for (index = 0; index < D_0035f4e0; index++) {
        if (D_0035f4dc[index * 2] == value) {
            found = 1;
            break;
        }
    }
    return found;
}
