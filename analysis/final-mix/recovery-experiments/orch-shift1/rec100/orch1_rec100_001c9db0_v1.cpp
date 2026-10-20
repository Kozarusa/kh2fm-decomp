#include "../common/types.h"
extern "C" s32 D_00351f30;
extern "C" s32 D_01d49980[];

s32 func_001c9db0(s32 value) {
    s32 count = D_00351f30;
    s32 index = 0;
    if (count > 0) {
        s32* pointer = D_01d49980;
        do {
            if (*pointer == value) {
                return 1;
            }
            pointer = pointer + 1;
            index = index + 1;
        } while (index < count);
    }
    return 0;
}