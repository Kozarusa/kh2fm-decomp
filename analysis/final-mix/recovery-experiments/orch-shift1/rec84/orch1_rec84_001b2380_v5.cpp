#include "../common/types.h"
struct Node {
    s32 count;
    Node* next;
    s32 field8;
    s32 fieldC;
    f32 scale;
    u32 buffer;
    Node* link;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" f32 D_0036d9cc;
extern "C" List D_01d48c80;
extern "C" u32 func_001050d8(u64);

void func_001b2380(Node* node, s32 count) {
    node->next = 0;
    f32 scale = D_0036d9cc;
    node->count = count;
    node->scale = scale;
    node->field8 = 0;
    node->fieldC = 0;
    node->buffer = func_001050d8(count << 4);
    if (D_01d48c80.tail == 0) {
        D_01d48c80.tail = node;
        D_01d48c80.head = node;
        node->link = 0;
    } else {
        D_01d48c80.tail->link = node;
        node->link = 0;
        D_01d48c80.tail = node;
    }
}
