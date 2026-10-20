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
struct List { Node* head; s32 count; };
extern "C" List D_004f3b40;

void func_00160b10(void) {
    Node* current = 0;
    Node* node;
    for (;;) {
        node = current ? current->next : D_004f3b40.head;
        current = node;
        if (node == 0) {
            D_004f3b40.head = 0;
            D_004f3b40.count = 0;
            return;
        }
        if ((node->flags & 4) == 0) {
            node->vtable->func(node);
        }
    }
}
