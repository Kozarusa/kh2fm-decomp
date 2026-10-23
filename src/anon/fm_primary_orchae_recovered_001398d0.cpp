#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_00139570(Node*);

// Preserve original registry aliases.
void func_001398d0(s32 key) asm("_Z13func_001398d0i");

void func_001398d0(s32 key) {
    Node* cur = 0;
    Node* node;
    Node* head;
    // why: volatile read keeps the original load order and branch layout
    while ((head = D_00347f80, node = (cur == 0 ? head->next : *(Node* volatile*)&cur->next), cur = node, node != 0)) {
        if (node->key == key) {
            func_00139570(node);
        }
    }
}
