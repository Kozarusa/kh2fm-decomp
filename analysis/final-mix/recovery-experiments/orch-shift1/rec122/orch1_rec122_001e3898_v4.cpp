#include "../common/types.h"
extern "C" s32* func_001e3650(...);

void func_001e3898(u64 handle, s32 amount) {
    s32* pointer = func_001e3650();
    s32 group = 4;
    do {
        s32 count = *pointer;
        pointer = pointer + 1;
        if (0 < count) {
            s32 remaining = count;
            do {
                remaining = remaining - 1;
                *pointer = *pointer + amount;
                pointer = pointer + 1;
            } while (remaining != 0);
        }
        group = group - 1;
    } while (group >= 0);
}