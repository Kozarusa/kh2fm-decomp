#include "../common/types.h"
extern "C" s16 D_00371840[];

s16* func_00243150(s32 value) {
    s16* result = 0;
    s32 index = 0;
    if (D_00371840[0] >= 0) {
        do {
            if (D_00371840[index * 6] == value) result = &D_00371840[index * 6];
            index++;
        } while (D_00371840[index * 6] >= 0);
    }
    return result;
}
