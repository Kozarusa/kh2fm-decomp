#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_00139570(Node*);

void func_001398d0(s32 key) {
    Node* cur = 0;
    // why: original loads the list head straight into a0 (the same register as the new node)
    register Node* node asm("$4");
    while ((node = (cur ? cur->next : D_00347f80->next), cur = node, node != 0)) {
        if (node->key == key) {
            func_00139570(node);
        }
    }
}
