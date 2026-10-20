#include "../common/types.h"

void func_001b0210(s32* object, s32 a, s32 b, s32 c) {
    if (object[2] < 0 && object[4] == 0) {
        object[6] = c;
    } else {
        if (b < object[3]) return;
        object[6] = c;
    }
    object[2] = a;
    object[3] = b;
}
