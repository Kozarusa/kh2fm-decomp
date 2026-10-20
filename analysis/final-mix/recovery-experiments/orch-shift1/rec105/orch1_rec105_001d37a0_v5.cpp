#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Node {
    volatile Quad q;
    volatile s32 a;
    volatile s32 b;
    volatile f32 f1;
    volatile f32 f2;
    volatile f32 f3;
    volatile s32 c;
    volatile f32 f4;
    volatile f32 f5;
    Node* volatile next;
};
struct List {
    Node* head;
    Node* tail;
};
extern "C" List D_01d5ba20;
extern "C" f32 D_0036e430;
extern "C" f32 D_0036e434;

void func_001d37a0(f32 value, Node* node, Node* source) {
    node->q = source->q;
    node->f3 = value;
    node->a = 0;
    node->b = 0;
    node->f4 = D_0036e430;
    node->f1 = value;
    node->f2 = value;
    node->f5 = D_0036e434;
    node->c = 0;
    if (D_01d5ba20.tail == 0) {
        D_01d5ba20.tail = node;
        D_01d5ba20.head = node;
        node->next = 0;
        return;
    }
    D_01d5ba20.tail->next = node;
    node->next = 0;
    D_01d5ba20.tail = node;
}
