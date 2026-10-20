#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Ring {
    s32 size;
    s32 high;
    s32 index;
    s32 pad;
    s32 pad2;
    Quad* items;
};

void func_001b2520(Ring* ring, Quad* value) {
    Quad* slot = ring->items + ring->index;
    if (slot != value) {
        *slot = *value;
        asm volatile("" ::: "memory"); // why: forces reload of fields after the quad copy
    }
    s32 next = ring->index + 1;
    s32 high = ring->high;
    if (next >= high) {
        high = next;
    }
    ring->high = high;
    ring->index = next % ring->size;
}
