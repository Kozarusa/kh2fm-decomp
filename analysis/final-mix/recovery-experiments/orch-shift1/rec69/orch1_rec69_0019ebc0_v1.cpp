#include "../common/types.h"
extern "C" u64 D_0034ecc8;
extern "C" void func_0015ee10(s32);

void func_0019ebc0() {
    s32 index = 0;
    do {
        if (((D_0034ecc8 >> index) & 1) != 0) {
            func_0015ee10(index);
        }
        index = index + 1;
    } while (index < 64);
}