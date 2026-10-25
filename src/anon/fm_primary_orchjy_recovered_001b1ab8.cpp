#include "../common/types.h"
struct Node {
    s32 value;
    Node* next;
    u8 pad[32];
};
struct List {
    Node* head;
    Node* tail;
};
struct Pool {
    Node nodes[16];
    s32 free[16];
    s32 count;
};
extern "C" List D_01d44100;
extern "C" Pool D_01d44108;

void func_001b1ab8(Node* node) {
    Node* previous;
    List* list;
    D_01d44108.free[D_01d44108.count++] = node - D_01d44108.nodes;
    if (node == D_01d44100.head) {
        D_01d44100.head = node->next;
        previous = 0;
    } else {
        for (previous = D_01d44100.head; previous->next != node; previous = previous->next) {
        }
        previous->next = node->next;
    }
    list = &D_01d44100; // why: original rematerializes the list base (lui/addiu) for the tail check, as in accepted 001ac5b8
    if (node == list->tail) {
        list->tail = previous;
    }
    node->next = 0;
}
