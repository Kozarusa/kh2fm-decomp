#include "../common/types.h"
// why: the original loads the entry time after the s32 index store, so the time shares a union with an s32 word to make the load alias that store
union TimerTime {
    s32 word;
    f32 time;
};
struct TimerEntry {
    s32 value;
    TimerTime time;
};
struct TimerQueue {
    s32 head;
    s32 index;
    TimerEntry entries[3];
    s32 current;
    f32 duration;
    f32 remaining;
};
extern "C" f32 D_00349e10;
extern "C" bool func_00197920(...);                     // copied from accepted caller fm_primary_oneword_recovered_00232510.cpp
// why: no accepted source declares it; parameters derived from registers (a0 queue, a1 value, $f12 time), void because it tail-calls accepted-void func_0014f578
extern "C" void func_001d2668(TimerQueue*, s32, f32);

// why: void per DEVIATIONS #36; exits 1-3 leave the direct result of func_00197920 (final non-void callee on those paths), exit 4 tail-calls func_001d2668 which tail-calls accepted-void func_0014f578: stale-b

void func_001d2750(TimerQueue* queue) {
    if (func_00197920()) {
        return;
    }
    s32 current = queue->current;
    if (current != 0) {
        f32 remaining = queue->remaining - D_00349e10;
        queue->remaining = remaining;
        s32 active = current;
        if (remaining <= 0.0f) {
            active = 0;
        }
        if (active != 0) {
            return;
        }
    }
    s32 index = queue->index;
    if (index != queue->head) {
        TimerEntry* entry = &queue->entries[index];
        queue->index = (index + 1) % 3;
        func_001d2668(queue, entry->value, entry->time.time);
    } else {
        if (current == 0) {
            return;
        }
        func_001d2668(queue, current, queue->duration);
    }
}
