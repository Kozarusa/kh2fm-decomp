#include "../common/types.h"
struct Node {
    u8 pad0[0x28];
    s32 key;
    u8 pad1[0x10];
    Node* next;
};
extern "C" Node* D_0034dca0;
extern "C" void func_001700e8(Node*, s32);

void func_001703a8(s32 value) {
    Node* node = D_0034dca0;
    while (node != 0) {
        Node* next = node->next;
        if (node->key == value) {
            func_001700e8(node, 1);
        }
        node = next;
    }
}