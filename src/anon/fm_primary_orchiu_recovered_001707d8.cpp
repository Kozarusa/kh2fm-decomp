#include "../common/types.h"
struct Node {
    u8 pad0[0x24];
    u32 flags;
    s32 key;
    u32 start;
    u32 length;
    u8 pad1[0x8];
    Node* next;
};
extern "C" Node* D_0034dca0;
extern "C" u32 D_0034dcb0;
extern "C" void func_001700e8(Node*, s32);
extern "C" void func_0016fc10(Node*);

void func_001707d8() {
    u32 limit = D_0034dcb0;
    Node* node = D_0034dca0;
    while (node != 0) {
        Node* next = node->next;
        if (node->key >= 0 && limit < node->length + node->start) {
            func_001700e8(node, 0);
        } else {
            func_0016fc10(node);
        }
        node = next;
    }
    node = D_0034dca0;
    while (node != 0) {
        Node* next = node->next;
        if (node->flags & 2) {
            func_001700e8(node, 0);
        }
        node = next;
    }
}
