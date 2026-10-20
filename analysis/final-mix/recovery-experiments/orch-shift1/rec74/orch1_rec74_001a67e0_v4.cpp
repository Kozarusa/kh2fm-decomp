#include "../common/types.h"
struct Node {
    u8 pad[0xc];
    Node* next;
};
extern "C" Node* D_01c6cb20;
extern "C" void func_00105110(void*);
extern "C" void func_001a5d48(void*);

void func_001a67e0(Node* node) {
    if (node != 0) {
        Node* previous = 0;
        Node* current;
        for (;;) {
            current = D_01c6cb20;
            if (previous != 0) {
                current = previous->next;
            }
            if (current != 0) {
                previous = current;
                if (current != node) {
                    continue;
                }
            }
            break;
        }
        if (node != 0) {
            func_001a5d48(node);
            func_00105110(node);
            // why: original calls the free as a normal call, not a tail call
            asm volatile("" ::: "memory");
        }
    }
}
