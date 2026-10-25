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

static inline Node* nextNode(Node* current) {
    List* list = D_00347f80;
    if (current == 0) {
        return list->head;
    }
    return current->next;
}

// Preserve original registry aliases.
void func_001397d8(s32 id) asm("_Z13func_001397d8i");

void func_001397d8(s32 id) {
    Node* node = 0;
    while ((node = nextNode(node)) != 0) {
        if (node->id == id) {
            node->vtable->callback(node);
        }
    }
}
