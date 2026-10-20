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
        do {
            current = D_01c6cb20;
            if (previous != 0) {
                current = previous->next;
            }
        } while (current != 0 && (previous = current, current != node));
        if (node != 0) {
            func_001a5d48(node);
            func_00105110(node);
        }
    }
}
