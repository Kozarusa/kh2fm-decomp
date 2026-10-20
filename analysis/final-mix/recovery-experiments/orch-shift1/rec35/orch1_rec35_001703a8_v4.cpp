#include "../common/types.h"
struct Node {
    u8 pad0[0x28];
    s32 key;
    u8 pad1[0x10];
    Node* next;
};
extern "C" Node* D_0034dca0;
extern "C" void func_001700e8(Node*, s32);

void func_001703a8(s32 value_in) {
    // why: pin value to s0 and next to s1 as in the original allocation
    register s32 value asm("$16") = value_in;
    register Node* next asm("$17");
    Node* node = D_0034dca0;
    while (node != 0) {
        next = node->next;
        if (node->key == value) {
            func_001700e8(node, 1);
        }
        node = next;
    }
}