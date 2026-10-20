#include "../common/types.h"
extern "C" s32 D_01d9e348;
extern "C" void func_001e01e8(s32, s32, u32);

void func_001e0230(s32 first, u32 second) {
    s32 node = 0;
    s32 head;
    while ((head = D_01d9e348, node = (node != 0) ? *(s32*)(node + 0x14) : head) != 0) {
        func_001e01e8(node, first, second);
    }
}
