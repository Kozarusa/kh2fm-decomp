#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Ring {
    s32 size;
    s32 high;
    s32 index;
    s32 pad;
    s32 pad2;
    s32* items;
};

void func_001b2520(Ring* ring, s32* value) {
    s32* slot = ring->items + ring->index * 4;
    if (slot != value) {
        *(Quad*)slot = *(Quad*)value;
    }
    s32 next = ring->index + 1;
    s32 high = ring->high;
    if (next >= high) {
        high = next;
    }
    ring->high = high;
    ring->index = next % ring->size;
}