#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Node {
    Quad q;
    s32 a;
    s32 b;
    f32 f1;
    f32 f2;
    f32 f3;
    s32 c;
    f32 f4;
    f32 f5;
    Node* next;
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
