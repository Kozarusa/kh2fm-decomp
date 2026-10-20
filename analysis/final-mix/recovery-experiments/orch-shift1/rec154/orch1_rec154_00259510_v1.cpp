#include "../common/types.h"
extern "C" s16 D_00372c30[];
s32 func_00259510(s32 value) {
    s32 result = 11;
    s32 index = 0;
    if (D_00372c30[0] != -1) {
        do {
            if (D_00372c30[index * 2] == value) return D_00372c30[index * 2 + 1];
            index++;
        } while (D_00372c30[index * 2] != -1);
    }
    return result;
}
