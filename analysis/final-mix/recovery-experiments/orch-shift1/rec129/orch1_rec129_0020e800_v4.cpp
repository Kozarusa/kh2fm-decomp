#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union Node {
    Quad quad;
    struct {
        u32 word0;
        Node* next;
    } f;
};
struct Slot {
    u32 pad[2];
    Node* tail;
    u32 pad2;
};
extern "C" Slot D_01dad550[];

void func_0020e800(Node* node, s32 value, s32 index) {
    node->quad = 0;
    node->f.word0 = (value - 1) | 0x20000000;
    if (index < 1) {
        index = 0;
    }
    if (index > 15) {
        index = 15;
    }
    Slot* slot = &D_01dad550[index];
    Node* old = slot->tail;
    Node* nxt = old->f.next;
    old->f.next = node;
    node->f.next = nxt;
    slot->tail = node;
}
