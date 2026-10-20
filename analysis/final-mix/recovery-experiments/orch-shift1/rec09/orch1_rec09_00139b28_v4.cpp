#include "../common/types.h"
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[8];
    s32 key;
};
extern "C" Node* D_00347f80;
extern "C" void func_00139708(Node*);

void func_00139b28(s32 key) {
    Node* prev = 0;
    Node* node;
    while (1) {
        if (prev != 0) {
            node = prev->next;
        } else {
            node = D_00347f80->next;
        }
        prev = node;
        if (node != 0) {
            if (node->key == key) {
                func_00139708(node);
            }
        } else {
            return;
        }
    }
}
