#include "../common/types.h"
extern "C" u32 func_00227da8(...);
extern "C" u32 func_002ff2e8(...);
struct Record { s32 first, second, third, fourth, fifth; u8 flags[3]; u8 data[25]; };
u32 func_0022f528(u8* object) {
    register s32 sentinel asm("$17") = -1; // why: original preserves repeated sentinel in s1
    asm("" : "+r"(sentinel)); // why: keeps sentinel in s1
    Record record;
    record.first = sentinel;
    record.second = sentinel;
    record.third = 0;
    record.flags[2] = 0;
    record.data[0] = 0;
    func_002ff2e8(record.data, object + 8);
    record.fourth = sentinel;
    record.fifth = sentinel;
s32 first = *(s16*)(object + 4);
    s32 second = *(s16*)(object + 6);
    record.second = second;
    asm volatile("" : "+m"(record.second) : "r"(first), "m"(record.fourth), "m"(record.fifth)); // why: keeps second-field store before first-field store with first preloaded
    record.first = first;
    record.third = 0;
    record.flags[0] = 0;
    record.flags[1] = 0;
    return func_00227da8(&record);
}
