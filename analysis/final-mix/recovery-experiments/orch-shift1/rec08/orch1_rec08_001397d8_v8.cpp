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
    while ((node = node == 0 ? D_00347f80->head : *(Node* volatile*)&node->next) != 0) {
        if (node->id == id) {
            node->vtable->callback(node);
        }
    }
}