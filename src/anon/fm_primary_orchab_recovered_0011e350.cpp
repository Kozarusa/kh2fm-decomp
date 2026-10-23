#include "../common/types.h"
struct Node {
    void** vtable;
};
struct Owner {
    u8 pad[0x10];
    Node* handler;
};
extern "C" Node* func_00132350(Node*);

// Preserve original registry aliases.
void func_0011e350(Owner* owner, Node* node) asm("_Z16ctarget_0011e350jjjj");

void func_0011e350(Owner* owner, Node* node) {
    while (node != 0) {
        Node* next = func_00132350(node);
        ((void (*)(Node*))node->vtable[0])(node);
        ((void (*)(Node*, Node*))owner->handler->vtable[1])(owner->handler, node);
        node = next;
    }
}
