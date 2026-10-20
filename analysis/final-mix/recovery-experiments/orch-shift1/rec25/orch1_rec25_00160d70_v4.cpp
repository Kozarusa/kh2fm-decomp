#include "../common/types.h"
struct Node {
    u8 pad[0x80];
    Node* next;
    u8 pad2[0x124];
    s32 owner;
};
extern "C" Node* D_004f3b38;
extern "C" void func_00160d18(Node*);

static inline Node* nextNode(Node* current) {
    if (current != 0) {
        return current->next;
    }
    return D_004f3b38;
}

void func_00160d70(s32 owner) {
    Node* current = 0;
    Node* node;
    while ((node = nextNode(current)) != 0) {
        current = node;
        if (node->owner == owner) {
            func_00160d18(node);
        }
    }
}
