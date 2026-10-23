#include "../common/types.h"
extern "C" s16 D_003741f0[];

s32 func_00282c68(s32 value) {
    s32 result = -1;
    s32 index = 0;
    if (D_003741f0[0] >= 0) {
        do {
            if (D_003741f0[index*2] == value) result = D_003741f0[index*2+1];
            index++;
        } while (D_003741f0[index*2] >= 0);
    }
    return result;
}
