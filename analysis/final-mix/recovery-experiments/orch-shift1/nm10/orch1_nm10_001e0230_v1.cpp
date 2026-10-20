#include "../common/types.h"
extern "C" s32 D_01d9e348;
extern "C" void func_001e01e8(s32, s32, u32);

void func_001e0230(s32 first, u32 second) {
    s32 node = 0;
    s32 next;
    do {
        if (node != 0) {
            next = *(s32*)(node + 0x14);
        } else {
            next = D_01d9e348;
        }
        if (next == 0) {
            break;
        }
        func_001e01e8(next, first, second);
        node = next;
    } while (true);
}
