#include "../common/types.h"
struct Node;
typedef void (*NodeFunc)(Node*);
struct Node {
    NodeFunc* vtable;
    u8 pad[92];
    Node* next;
};

void func_00199cd0(u32* object) {
    object[1] |= 1;
    Node* node = (Node*)object[3];
    while (node != 0) {
        Node* next = node->next;
        if (node != 0) {
            node->vtable[1](node);
        }
        node = next;
    }
    object[3] = 0;
    object[4] = 0;
}
