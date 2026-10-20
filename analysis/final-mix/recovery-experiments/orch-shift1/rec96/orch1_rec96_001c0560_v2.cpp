#include "../common/types.h"
extern "C" s32 D_01d49350;
extern "C" void func_001c0490(s32);

void func_001c0560() {
    s32 object = 0;
    s32 next;
    while (1) {
        next = D_01d49350;
        if (object != 0) {
            next = *(s32*)(object + 0x50);
        }
        object = next;
        if (next == 0) {
            return;
        }
        func_001c0490(next);
    }
}
