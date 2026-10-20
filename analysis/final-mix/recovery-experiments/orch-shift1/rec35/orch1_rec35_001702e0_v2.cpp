#include "../common/types.h"
struct Node {
    u8 pad0[0x30];
    s32 key;
    u8 pad1[8];
    Node* next;
};
extern "C" Node* D_0034dca0;

Node* func_001702e0(s32 value) {
    Node* node = 0;
    while (1) {
        Node* next = D_0034dca0;
        if (node != 0) {
            next = node->next;
        }
        node = next;
        if (node == 0) {
            return 0;
        }
        if (node->key == value) {
            return node;
        }
    }
}