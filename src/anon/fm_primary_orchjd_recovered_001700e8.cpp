#include "../common/types.h"
struct Node {
    u8 pad[0x3c];
    Node* next;
};
extern "C" Node* D_0034dca0[];
extern "C" s32 func_0016fb00(Node*);

s32 func_001700e8(Node* object) {
    Node* head = D_0034dca0[0];
    Node* previous;
    if (object == head) {
        Node* next = object->next;
        previous = 0;
        D_0034dca0[0] = next;
    } else {
        Node* current = head->next;
        if (current != object) {
            do {
                Node* next = current->next;
                previous = current;
                if (next == object) {
                    break;
                }
                current = next;
            } while (1);
        } else {
            previous = head;
        }
        previous->next = object->next;
    }
    if (object == D_0034dca0[1]) {
        D_0034dca0[1] = previous;
    }
    object->next = 0;
    return func_0016fb00(object);
}
