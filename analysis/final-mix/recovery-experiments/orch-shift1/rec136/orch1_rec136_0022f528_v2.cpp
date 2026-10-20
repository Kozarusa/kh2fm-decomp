#include "../common/types.h"
extern "C" u32 func_00227da8(...);
extern "C" u32 func_002ff2e8(...);
struct Record { s32 first, second, third, fourth, fifth; u8 flags[3]; u8 data[25]; };
u32 func_0022f528(u8* object) {
    register u8* source asm("$16") = object; // why: original preserves object in s0
    asm("" : "+r"(source)); // why: keeps preserved object in s0
    Record record;
    record.first = -1;
    record.second = -1;
    record.third = 0;
    record.flags[2] = 0;
    record.data[0] = 0;
    func_002ff2e8(record.data, source + 8);
    record.fifth = -1;
    record.fourth = -1;
    record.second = *(s16*)(source + 6);
    record.first = *(s16*)(source + 4);
    record.third = 0;
    record.flags[0] = 0;
    record.flags[1] = 0;
    return func_00227da8(&record);
}
