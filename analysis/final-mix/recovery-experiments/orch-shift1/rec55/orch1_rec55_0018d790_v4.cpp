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
    Node* iter = node;
    while (node != 0) {
        Node* next;
        if (iter != 0) {
            next = iter->next;
        } else {
            next = D_01c60cd8;
        }
        iter = next;
        if (node != 0) {
            node->vtable->slot1(node);
        }
        node = next;
    }
    D_01c60ce0 = 0;
}