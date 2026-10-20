#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" s32* func_001d5b78(s32, s32);

s32 func_001d5d20() {
    s32* entry = func_001d5b78(0, 1);
    s32 total = *(s32*)(D_0032bb30 + 14052);
    s32 count = D_0032bb30[13606];
    if (1 < count) {
        s32 remaining = count - 1;
        do {
            remaining = remaining - 1;
            total = total + entry[1];
            entry = entry + 2;
        } while (remaining != 0);
    }
    return total;
}
