#include "../common/types.h"
struct Node {
    u8 pad[0x3c];
    Node* next;
};
extern "C" Node* D_0034dca0[];
extern "C" void func_0016fb00(Node*);

void func_001700e8(Node* object) {
    Node* previous;
    if (object == D_0034dca0[0]) {
        D_0034dca0[0] = object->next;
        previous = 0;
    } else {
        Node* current = D_0034dca0[0]->next;
        previous = D_0034dca0[0];
        while (current != object) {
            Node* next = current->next;
            previous = current;
            current = next;
        }
        previous->next = object->next;
    }
    if (object == D_0034dca0[1]) {
        D_0034dca0[1] = previous;
    }
    object->next = 0;
    func_0016fb00(object);
}