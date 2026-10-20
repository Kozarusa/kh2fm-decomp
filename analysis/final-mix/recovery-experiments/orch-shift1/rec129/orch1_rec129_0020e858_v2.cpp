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
extern "C" Slot D_01dac550[];

void func_0020e858(Node* node, s32 value, s32 index) {
    node->quad = 0;
    asm volatile("" ::: "memory");  // why: keeps store order and blocks reordering
    node->f.word0 = (value - 1) | 0x20000000;
    if (index < 1) {
        index = 0;
    }
    if (index > 255) {
        index = 255;
    }
    Slot* slot = &D_01dac550[index];
    Node* old = ((volatile Slot*)slot)->tail;  // why: original loads tail only after the clamps
    Node* nxt = old->f.next;
    old->f.next = node;
    node->f.next = nxt;
    slot->tail = node;
}
