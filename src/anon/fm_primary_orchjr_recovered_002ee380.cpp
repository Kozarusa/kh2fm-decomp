#include "../common/types.h"
struct Node {
    u32 vtable;
    u8 pad[0x1c];
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" List D_01e2c080;
extern "C" u8 D_00363808[];
extern "C" u8 D_003637e0[];

void func_002ee380(Node* node) {
    Node* previous;
    List* list;
    node->vtable = (u32)D_00363808;
    if (node == D_01e2c080.head) {
        D_01e2c080.head = node->next;
        previous = 0;
    } else {
        for (previous = D_01e2c080.head; previous->next != node; previous = previous->next) {
        }
        previous->next = node->next;
    }
    list = &D_01e2c080;
    if (node == list->tail) {
        list->tail = previous;
    }
    node->next = 0;
    node->vtable = (u32)D_003637e0;
}
