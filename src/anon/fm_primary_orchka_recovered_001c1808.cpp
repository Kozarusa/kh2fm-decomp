#include "../common/types.h"
extern "C" u32 func_001db8b8(s32,s32);

void func_001c1808(s32 node) {
    s32 owner = *(s32*)(node + 0x1c);
    s32* list = (s32*)(owner + 0xc);
    s32 head = list[0];
    s32 prev;
    if (node == head) {
        prev = 0;
        list[0] = *(s32*)(node + 0x24);
    } else {
        prev = head;
        while (*(s32*)(prev + 0x24) != node) {
            prev = *(s32*)(prev + 0x24);
        }
        *(s32*)(prev + 0x24) = *(s32*)(node + 0x24);
    }
    if (node == list[1]) {
        list[1] = prev;
    }
    *(s32*)(node + 0x24) = 0;
    func_001db8b8(*(s32*)(node + 0x1c) + 0x14, node);
    asm volatile("" ::: "memory"); // why: preserve original non-tail call epilogue
}
