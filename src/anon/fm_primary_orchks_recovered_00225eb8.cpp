#include "../common/types.h"
struct HeapBlock {
    HeapBlock* next;
    HeapBlock* prev;
    u8 used;
    u32 size;
};
struct HeapHeader {
    u32 field0;
    u32 field4;
    HeapBlock* first;
};

u8* func_00225eb8(HeapHeader* heap, u32 request, s32 mode) {
    HeapBlock* block = heap->first;
    HeapBlock* found = 0;
    u32 need = ((request + 63) & ~63u) + 64;
    while (block != 0) {
        if (block->used == 0 && need < block->size) {
            found = block;
            if (mode != 1) {
                break;
            }
        }
        block = block->next;
    }
    if (found == 0) {
        return 0;
    }
    u32 rest = found->size - need;
    if (rest >= 128) {
        if (mode != 1) {
            HeapBlock* split = (HeapBlock*)((u8*)found + need);
            HeapBlock* next = found->next;
            split->size = rest;
            split->next = next;
            split->prev = found;
            split->used = 0;
            if (next != 0) {
                next->prev = split;
            }
            found->next = split;
            found->used = 1;
            found->size = need;
        } else {
            HeapBlock* next = found->next;
            HeapBlock* old = found;
            found = (HeapBlock*)((u8*)found + rest);
            found->used = mode;
            found->size = need;
            found->next = next;
            found->prev = old;
            if (next != 0) {
                next->prev = found;
            }
            old->size = rest;
            old->used = 0;
            old->next = found;
        }
    } else {
        found->used = 1;
    }
    return (u8*)found + 64;
}
