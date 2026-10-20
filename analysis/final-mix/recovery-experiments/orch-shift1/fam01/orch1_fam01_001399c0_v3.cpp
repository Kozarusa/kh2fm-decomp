#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_00139598(Node*);

void func_001399c0(s32 key) {
    Node* cur = 0;
    Node* node;
    // why: volatile read keeps the original load order and branch layout
    while (1) {
        if (cur == 0) {
            node = D_00347f80;
            node = *(Node* volatile*)&node->next;
        } else {
            node = *(Node* volatile*)&cur->next;
        }
        cur = node;
        if (node == 0) {
            return;
        }
        if (node->key == key) {
            func_00139598(node);
        }
    }
}
