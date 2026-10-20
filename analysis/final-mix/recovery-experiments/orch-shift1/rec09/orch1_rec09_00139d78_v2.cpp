#include "../common/types.h"
struct Node {
    u8 pad0[4];
    Node* next;
    u8 pad8[92];
    Node* target;
};
extern "C" Node* D_00347f80;

static inline Node* nextNode(Node* current) {
    Node* head = D_00347f80;
    if (current == 0) {
        return head->next;
    }
    return current->next;
}

u8 func_00139d78(Node* wanted) {
    Node* node = 0;
    D_00347f80->target = wanted;
    while ((node = nextNode(node)) != 0) {
        if (node == wanted) {
            return 1;
        }
    }
    return 0;
}
