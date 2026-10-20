#include "../common/types.h"
struct Node {
    u32 vtable;
    u8 pad[0x78];
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" List D_01c6ced0;
extern "C" u8 D_00350c50[];

void func_001ac5b8(Node* node) {
    Node* previous;
    Node* current;
    List* list;
    node->vtable = (u32)D_00350c50;
    if (node == D_01c6ced0.head) {
        D_01c6ced0.head = node->next;
        previous = 0;
    } else {
        previous = D_01c6ced0.head;
        current = previous->next;
        if (current != node) {
            do {
                previous = current;
                current = current->next;
            } while (current != node);
        }
        previous->next = node->next;
    }
    list = &D_01c6ced0;
    if (node == list->tail) {
        list->tail = previous;
    }
    node->next = 0;
}
