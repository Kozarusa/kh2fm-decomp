#include "../common/types.h"
extern "C" bool func_001a6d08(u32);
extern "C" s8 D_00371f30[];

s32 func_0024ac88(void) {
    s32 result = 1;
    s8* base = D_00371f30;
    asm("" : "+r"(base)); // why: original materializes the table base before adding 28
    s8* cursor = base + 28;
    asm("" : "+r"(cursor)); // why: original forms the cursor before the result flag
    register s32 index asm("$16"); // why: original loop counter occupies s0
    for (index = 0; index < 4; index++) {
        s8 flag = *cursor++;
        if (flag < 0) break;
        if (!func_001a6d08(flag)) {
            result = 0;
            break;
        }
    }
    if (result != 0) {
        cursor = D_00371f30;
        for (index = 0; index < 4; index++) {
            s8 flag = *(s8*)((u32)index + (u32)cursor + 32);
            if (flag < 0) break;
            if (func_001a6d08(flag)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}
