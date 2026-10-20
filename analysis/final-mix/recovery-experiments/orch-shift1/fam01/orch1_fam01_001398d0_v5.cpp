#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" u32 func_00139570(Node*);

void func_001398d0(s32 key) {
    Node* cur = 0;
    Node* node;
top:
    if (cur != 0) goto from_cur;
    node = D_00347f80->next;
merge:
    cur = node;
    if (node == 0) {
        return;
    }
    if (node->key == key) {
        func_00139570(node);
    }
    goto top;
from_cur:
    node = cur->next;
    goto merge;
}
