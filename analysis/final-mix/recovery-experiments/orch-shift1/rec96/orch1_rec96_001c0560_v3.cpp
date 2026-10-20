#include "../common/types.h"
extern "C" s32 D_01d49350;
extern "C" void func_001c0490();

void func_001c0560() {
    s32 object = 0;
    s32 next;
    while (1) {
        next = object ? *(s32*)(object + 0x50) : D_01d49350;
        object = next;
        if (next == 0) {
            return;
        }
        func_001c0490();
    }
}
