#include "../common/types.h"
// why: the original masks the lbu result again (andi 0xff) before comparing, the code shape of an 8-bit bitfield read
struct Counter {
    u32 count : 8;
};
extern "C" u8* func_0016e920(u32);
// why: exact types of the accepted definition fm_primary_orchcx_recovered_001dba18.cpp; extern "C" as every accepted caller declares it (for example fm_primary_fourwordfresh_recovered_0022ae98.cpp)
extern "C" u8* func_001dba18(s32);
extern "C" u8* func_001c16f0(u32, u8*);

u8* func_001d6790(f32* bounds) {
    u8* manager = func_001dba18((s32)func_0016e920(0x848));
    u32 list = *(u32*)(manager + 0x9f4);
    register u8* cursor asm("$2") = 0; // why: original keeps the cursor in v0 across the loop and copies it to a1 at the loop top
    while ((cursor = func_001c16f0(list, cursor)) != 0) {
        Counter* counter = (Counter*)(cursor + 20);
        if (counter->count == **(u32**)(cursor + 0x5c) &&
            bounds[0] <= *(f32*)cursor && *(f32*)cursor <= bounds[3] &&
            bounds[2] <= *(f32*)(cursor + 8) && *(f32*)(cursor + 8) <= bounds[5]) {
            cursor[23] = 0;
            counter->count++;
        }
    }
    return cursor;
}
