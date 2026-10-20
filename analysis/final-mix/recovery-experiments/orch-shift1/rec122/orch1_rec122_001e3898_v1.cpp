#include "../common/types.h"
extern "C" u64 func_001e3650(...);

void func_001e3898(u64 handle, s32 amount) {
    s32* pointer = (s32*)func_001e3650();
    s32 group = 4;
    s32 count = *pointer;
    while (true) {
        pointer = pointer + 1;
        if (0 < count) {
            do {
                count = count - 1;
                *pointer = *pointer + amount;
                pointer = pointer + 1;
            } while (count != 0);
        }
        group = group - 1;
        if (group < 0) break;
        count = *pointer;
    }
}