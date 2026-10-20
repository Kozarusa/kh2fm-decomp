#include "../common/types.h"
struct Node;
struct VTable {
    void* slot0;
    void (*slot1)(Node*);
};
struct Node {
    VTable* vtable;
    u8 pad[0xbc];
    Node* next;
};
extern "C" Node* D_01c60cd8;
extern "C" u8 D_01c60ce0;

void func_0018d790() {
    Node* node = D_01c60cd8;
    while (node != 0) {
        Node* next = D_01c60cd8;
        if (node != 0) {
            next = node->next;
            node->vtable->slot1(node);
        }
        node = next;
    }
    D_01c60ce0 = 0;
}