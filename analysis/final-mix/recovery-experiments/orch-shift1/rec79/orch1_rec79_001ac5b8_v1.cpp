#include "../common/types.h"
struct Node {
    u32 vtable;
    u8 pad[0x78];
    Node* next;
};
extern "C" Node* D_01c6ced0;
extern "C" Node* D_01c6ced4;
extern "C" u8 D_00350c50[];

void func_001ac5b8(Node* node) {
    Node* previous;
    Node* current;
    node->vtable = (u32)D_00350c50;
    if (node == D_01c6ced0) {
        D_01c6ced0 = node->next;
        previous = 0;
    } else {
        current = D_01c6ced0->next;
        previous = D_01c6ced0;
        while (current != node) {
            previous = current;
            current = current->next;
        }
        previous->next = node->next;
    }
    if (node == D_01c6ced4) {
        D_01c6ced4 = previous;
    }
    node->next = 0;
}
