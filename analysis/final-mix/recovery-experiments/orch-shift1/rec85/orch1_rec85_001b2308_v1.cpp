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
extern "C" f32 D_0036d9c8;
extern "C" Node* D_01d48c80;
extern "C" Node* D_01d48c84;
extern "C" u32 func_001050d8(u64);

void func_001b2308(Node* node, s32 count) {
    node->tail = 0;
    node->count = count;
    node->value = D_0036d9c8;
    node->a = 0;
    node->b = 0;
    node->buffer = func_001050d8(count << 4);
    Node* last = D_01d48c84;
    if (last == 0) {
        D_01d48c84 = node;
        D_01d48c80 = node;
        node->next = 0;
    } else {
        last->next = node;
        node->next = 0;
        D_01d48c84 = node;
    }
}
