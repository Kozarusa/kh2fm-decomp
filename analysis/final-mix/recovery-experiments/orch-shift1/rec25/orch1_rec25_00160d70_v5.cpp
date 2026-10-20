#include "../common/types.h"
struct Node {
    u8 pad[0x80];
    Node* next;
    u8 pad2[0x124];
    s32 owner;
};
extern "C" Node* volatile D_004f3b38; // why: keeps the head load on its own path
extern "C" void func_00160d18(Node*);

void func_00160d70(s32 owner) {
    Node* current = 0;
    Node* node;
    while ((node = current ? current->next : D_004f3b38) != 0) {
        current = node;
        if (node->owner == owner) {
            func_00160d18(node);
        }
    }
}

