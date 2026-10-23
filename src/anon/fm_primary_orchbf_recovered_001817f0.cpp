#include "../common/types.h"

extern "C" void func_0019ee80(u32, u32);
extern "C" s32 D_0036c710[];

void func_001817f0(s32 key) {
    s32* entry = D_0036c710;
    s32 end = (s32)(D_0036c710 + 42);
    do {
        if (*entry == key) {
            func_0019ee80(entry[1], entry[2]);
        }
        entry += 3;
    } while ((s32)entry < end);
}
