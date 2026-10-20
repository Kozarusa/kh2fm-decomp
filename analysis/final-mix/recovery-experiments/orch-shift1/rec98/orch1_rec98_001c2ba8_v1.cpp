#include "../common/types.h"
extern "C" u32 D_01d49530[];
extern "C" u32 func_001dc9d0(u32);

void func_001c2ba8() {
    u32* slot = D_01d49530;
    s32 index = 7;
    do {
        if (*slot != 0) {
            if (func_001dc9d0(*slot) == 0) {
                *slot = 0;
            }
        }
        index = index - 1;
        slot = slot + 1;
    } while (index >= 0);
}
