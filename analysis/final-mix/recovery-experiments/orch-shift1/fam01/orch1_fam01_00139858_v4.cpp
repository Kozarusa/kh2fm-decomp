#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" void func_00139580(Node*);

void func_00139858(s32 key) {
    Node* cur = 0;
    Node* node;
    do {
        if (cur != 0) {
            node = cur->next;
        } else {
            node = D_00347f80->next;
        }
        cur = node;
        if (node == 0) {
            return;
        }
        if (node->key == key) {
            func_00139580(node);
        }
    } while (1);
}
