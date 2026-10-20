#include "../common/types.h"
struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; };
extern "C" Node* D_00347f80;
extern "C" void func_00139580(Node*);

void func_00139858(s32 key) {
    Node* node = 0;
    while (1) {
        if (node == 0) {
            node = D_00347f80->next;
        } else {
            node = node->next;
        }
        if (node == 0) {
            return;
        }
        if (node->key == key) {
            func_00139580(node);
        }
    }
}
