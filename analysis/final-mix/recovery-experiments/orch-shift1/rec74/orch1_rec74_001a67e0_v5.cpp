#include "../common/types.h"
struct Node {
    u8 pad[0xc];
    Node* next;
};
extern "C" Node* D_01c6cb20;
extern "C" void func_00105110(void*);
extern "C" void func_001a5d48(void*);

static inline Node* step(Node* previous) {
    Node* result = D_01c6cb20;
    if (previous != 0) {
        result = previous->next;
    }
    return result;
}

void func_001a67e0(Node* node) {
    if (node != 0) {
        Node* current = 0;
        while ((current = step(current)) != 0 && current != node) {
        }
        if (node != 0) {
            func_001a5d48(node);
            func_00105110(node);
            // why: original calls the free as a normal call, not a tail call
            asm volatile("" ::: "memory");
        }
    }
}
