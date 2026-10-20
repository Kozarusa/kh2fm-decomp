#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_001395a8(Node*);

void func_00139948(s32 key) {
    Node* cur = 0;
    Node* node;
    // why: the original loads the list head into a0 and chases the next link in the same register
    while ((node = (cur == 0 ? ({ register Node* head asm("$4") = D_00347f80; head->next; }) : *(Node* volatile*)&cur->next), cur = node, node != 0)) {
        if (node->key == key) {
            func_001395a8(node);
        }
    }
}
