#include "../common/types.h"
extern "C" s32* D_0035f630;
extern "C" const void* D_00374c80[7];
extern "C" u32 func_00287bc0(void);

// why: every exit leaves the function's own constant or flag in v0, so the return is s32

s32 func_002b3b78(s32 slot) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_00374c80
    static const void* targets[7] asm("fm_switch_table_002b3b78") = {
        &&one, &&scan, &&zero, &&one, &&zero, &&zero, &&zero};
    s32 result = 0;
    if (slot < 0) {
        return 1;
    }
    {
        u32 index = func_00287bc0() - 27;
        if (index >= 7) goto done;
        goto *D_00374c80[index];
    }
scan:
    {
        s32 found = 0;
        s32 count = 0;
        s32* entry = D_0035f630;
        do {
            s32 value = *entry;
            if (value & 0x1000000) {
                if (found == slot) {
                    result = (value >> 25) & 1;
                    goto done;
                }
                found++;
            }
            count++;
            entry += 9;
        } while (count < 10);
    }
    goto done;
one:
    result = 1;
    goto done;
zero:
    result = 0;
done:
    return result;
}
