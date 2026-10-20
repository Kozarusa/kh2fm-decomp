#include "../common/types.h"
struct Node {
    u8 pad[0x80];
    Node* next;
    u8 pad2[0x124];
    s32 owner;
};
extern "C" Node* D_004f3b38;
extern "C" void func_00160d28(Node*);

void func_00160de0(s32 owner) {
    Node* current = 0;
    Node* node;
    while ((node = current ? current->next : D_004f3b38) != 0) {
        current = node;
        if (node->owner == owner) {
            func_00160d28(node);
        }
    }
}

