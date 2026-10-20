#include "../common/types.h"
struct Node {
    s32 count;
    struct Node* tail;
    s32 a;
    s32 b;
    f32 value;
    u32 buffer;
    struct Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" f32 D_0036d9c8[];
extern "C" List D_01d48c80;
extern "C" u32 func_001050d8(u64);

void func_001b2308(Node* node, s32 count) {
    node->tail = 0;
    f32 value = D_0036d9c8[0];
    node->count = count;
    node->value = value;
    node->a = 0;
    node->b = 0;
    node->buffer = func_001050d8(count << 4);
    if (D_01d48c80.tail == 0) {
        D_01d48c80.tail = node;
        D_01d48c80.head = node;
        node->next = 0;
    } else {
        D_01d48c80.tail->next = node;
        node->next = 0;
        D_01d48c80.tail = node;
    }
}
