#include "../common/types.h"
struct __attribute__((aligned(16))) Node {
    u32 word0;
    Node* next;
    u32 word2;
    u32 word3;
};
struct Slot {
    u32 pad[2];
    Node* tail;
    u32 pad2;
};
extern "C" Slot D_01dad550[];

void func_0020e800(Node* node, s32 value, s32 index) {
    Node zero = {0, 0, 0, 0};
    *node = zero;
    node->word0 = (value - 1) | 0x20000000;
    if (index < 1) {
        index = 0;
    }
    if (index > 15) {
        index = 15;
    }
    Slot* slot = &D_01dad550[index];
    Node* old = slot->tail;
    Node* nxt = old->next;
    old->next = node;
    node->next = nxt;
    slot->tail = node;
}
