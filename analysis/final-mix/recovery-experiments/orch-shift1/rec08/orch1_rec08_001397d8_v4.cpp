#include "../common/types.h"

struct Node;
struct Vtable {
    u8 pad[0x14];
    void (*callback)(Node*);
};
struct Node {
    Vtable* vtable;
    Node* next;
    u32 pad8;
    u32 padc;
    s32 id;
};
struct List {
    u32 pad0;
    Node* head;
};
extern "C" List* D_00347f80;

void func_001397d8(s32 id) {
    Node* node = 0;
    while (1) {
        Node* current;
        if (node != 0) {
            current = node->next;
        } else {
            current = D_00347f80->head;
        }
        node = current;
        if (node == 0) {
            break;
        }
        if (node->id == id) {
            node->vtable->callback(node);
        }
    }
}