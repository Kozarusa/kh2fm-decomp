#include "../common/types.h"
extern "C" s32 func_0019c5d0(s32);

u32 func_00176258(s32 object) {
    s32* pointer = (s32*)(object + 0xaf8);
    s32 index = 0;
    do {
        s32 target = *pointer++;
        if (target == 0 || func_0019c5d0(target) != 0) {
            index++;
            continue;
        }
        return 1;
    } while (index < 2);
    return 0;
}
