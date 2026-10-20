#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_001396d0(Node*);

void func_00139a38(s32 key) {
    Node* cur = 0;
    Node* node;
    // why: bind the list head to a0 like the original, which chains both loads in a0
    register Node* head asm("$4");
    while ((node = (cur == 0 ? (head = D_00347f80, head->next) : *(Node* volatile*)&cur->next), cur = node, node != 0)) {
        if (node->key == key) {
            func_001396d0(node);
        }
    }
}
