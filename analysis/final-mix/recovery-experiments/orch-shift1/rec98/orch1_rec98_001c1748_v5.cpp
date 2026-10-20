#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Node;
struct List {
    Node* head;
    Node* tail;
};
struct Owner {
    u8 pad0[8];
    u8 kind;
    u8 pad1[3];
    List list;
};
struct Node {
    Quad data;
    u32 value;
    u8 flag0;
    u8 flag1;
    u8 kindCopy;
    u8 flag3;
    u8 flag4;
    u8 pad[3];
    Owner* owner;
    u32 zero;
    Node* next;
};

void func_001c1748(Node* node, Owner* owner, Quad* source, u32 value) {
    List* list = &owner->list;
    Quad temp = *source;
    node->data = temp;
    node->value = value;
    node->flag1 = 0x80;
    node->flag0 = 0;
    node->kindCopy = owner->kind;
    node->flag3 = 0xff;
    node->flag4 = 0;
    node->owner = owner;
    node->zero = 0;
    if (list->tail == 0) {
        list->tail = node;
        list->head = node;
        node->next = 0;
        return;
    }
    list->tail->next = node;
    node->next = 0;
    list->tail = node;
}

