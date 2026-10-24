#include "../common/types.h"
struct Node {
    u8 pad00[0x28];
    Node* next28;
};
struct NodeList {
    Node* head;
    Node* tail;
};
extern "C" NodeList D_004f6290;
extern "C" u32 func_0016c7d8(u32);
extern "C" u32 func_0016cab8(u32);

// Preserve original registry aliases.
void func_0016d110() asm("_Z17ttarget0_0016d110v");

void func_0016d110() {
    register Node* node asm("$17") = D_004f6290.head; // why: original keeps the current node in s1
    Node* cursor = node;
    while (node != 0) {
        Node* next;
        if (cursor == 0) {
            next = D_004f6290.head;
        } else {
            next = cursor->next28;
        }
        cursor = next;
        if (node != 0) {
            func_0016cab8((u32)node);
            func_0016c7d8((u32)node);
        }
        node = next;
    }
    D_004f6290.head = 0;
    D_004f6290.tail = 0;
}
