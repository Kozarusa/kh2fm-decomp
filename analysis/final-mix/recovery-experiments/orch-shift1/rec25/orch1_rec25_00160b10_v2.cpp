#include "../common/types.h"
struct Node;
struct VTable { u32 slot0; u32 slot1; void (*func)(Node*); };
struct Node {
    VTable* vtable;
    u8 pad[0x80];
    Node* next;
    u8 pad2[0xf8];
    u32 flags;
};
extern "C" Node* D_004f3b40;
extern "C" s32 D_004f3b44;

void func_00160b10(void) {
    Node* current = 0;
    Node* node;
    for (;;) {
        node = D_004f3b40;
        if (current != 0) {
            node = current->next;
        }
        if (node == 0) break;
        current = node;
        if ((node->flags & 4) == 0) {
            node->vtable->func(node);
        }
    }
    D_004f3b40 = 0;
    D_004f3b44 = 0;
}

