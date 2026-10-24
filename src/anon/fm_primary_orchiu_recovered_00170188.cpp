#include "../common/types.h"
struct Node {
    u8 pad0[0x28];
    s32 priority;
    u8 pad1[0x10];
    Node* next;
};
extern "C" Node* D_0034dca0[];

void func_00170188(Node* object) {
    Node* prev = 0;
    Node* node;
    while ((node = (prev != 0) ? prev->next : D_0034dca0[0]) != 0) {
        s32 value = object->priority;
        if (value >= 0) {
            if (value < node->priority) {
                break;
            }
        } else {
            if (node->priority >= 0) {
                prev = node;
                continue;
            }
            if (value < node->priority) {
                break;
            }
        }
        prev = node;
    }
    if (prev == 0) {
        Node* head = D_0034dca0[0];
        if (head == 0) {
            D_0034dca0[1] = object;
            D_0034dca0[0] = object;
            object->next = 0;
            return;
        }
        object->next = head;
        D_0034dca0[0] = object;
        return;
    }
    if (prev == D_0034dca0[1]) {
        prev->next = object;
        object->next = 0;
        D_0034dca0[1] = object;
        return;
    }
    object->next = prev->next;
    prev->next = object;
}
