#include "../common/types.h"
extern "C" s32 D_003718d0[];
u32 func_00243190(s32 value) {
    u32 index = 0;
    s32* pointer = D_003718d0;
    do {
        s32 current = *pointer++;
        if (current == value) break;
        ++index;
    } while (index < 11);
    return index;
}
