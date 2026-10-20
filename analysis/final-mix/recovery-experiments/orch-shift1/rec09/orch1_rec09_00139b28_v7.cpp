#include "../common/types.h"
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[8];
    s32 key;
};
extern "C" Node* D_00347f80;
extern "C" void func_00139708(Node*);

static inline Node* nextNode(Node* current) {
    return current ? current->next : D_00347f80->next;
}

void func_00139b28(s32 key) {
    Node* node = 0;
    while ((node = nextNode(node)) != 0) {
        if (node->key == key) {
            func_00139708(node);
        }
    }
}


