#include "../common/types.h"
struct Node {
    u8 pad[0x3c];
    Node* next;
};
extern "C" Node* D_0034dca0[];
extern "C" void func_0016fb00(Node*);

void func_001700e8(Node* object) {
    Node* head = D_0034dca0[0];
    Node* previous;
    if (object == head) {
        D_0034dca0[0] = object->next;
        previous = 0;
    } else {
        Node* current = head->next;
        previous = head;
        while (current != object) {
            previous = current;
            current = current->next;
        }
        previous->next = object->next;
    }
    if (object == D_0034dca0[1]) {
        D_0034dca0[1] = previous;
    }
    object->next = 0;
    func_0016fb00(object);
}