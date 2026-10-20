#include "../common/types.h"

struct Node {
    Node* next;
};

struct Owner {
    u8 pad0[116];
    Node* list;
    u8 pad1[8];
    u32 value;
};

extern "C" u32 D_01d9e6e4;
extern "C" void func_001e7798(u32, u32);
extern "C" void func_001e7be0(Node*);

void func_001e7cc0(Owner* object) {
    Node* node = object->list;
    if (node != 0) {
        Node* next;
        do {
            next = node->next;
            func_001e7be0(node);
            node = next;
        } while (node != 0);
        object->list = 0;
    } else {
        object->list = 0;
    }
    if (object->value != 0) {
        func_001e7798(D_01d9e6e4, object->value);
        object->value = 0;
    }
}
