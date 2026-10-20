#include "../common/types.h"

struct Entry {
    u8 pad[1312];
    s32 first;
    s32 second;
    u8 pad2[8];
};

struct Queue {
    s32 head;
    s32 tail;
    u8 pad[8];
    Entry entries[8];
};

extern "C" u8* D_00347d64;

void func_00138190(s32 first, s32 second) {
    Queue* queue = (Queue*)(D_00347d64 + 48);
    s32 head = queue->head;
    if ((head - queue->tail + 8) % 8 < 7) {
        queue->head = (head + 1) % 8;
        queue->entries[head].first = first;
        queue->entries[head].second = second;
    }
}
