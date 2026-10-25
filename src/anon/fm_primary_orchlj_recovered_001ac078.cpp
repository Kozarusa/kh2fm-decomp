#include "../common/types.h"
// why: recovered call sites (fm_primary_orchjq_recovered_001aca98.cpp, fm_primary_orchcc_recovered_001abdf0.cpp)
// declare it this way; the result is unused here because func_001ac078 is void (mixed-exit ruling 2026-10-20)
extern "C" u32 func_00239bf8(s32, s32);

// Preserve original registry aliases.
void func_001ac078(u8* object, s32 first, s32 second, s32 third) asm("_Z16wtarget_001ac078jjjj");

void func_001ac078(u8* object, s32 first, s32 second, s32 third) {
    register u8* cursor asm("$14") = object; // why: the original keeps the object copy in t6 for the byte stores
    cursor[1] = second;
    register s32 saved asm("$12") = first; // why: the original keeps first in t4 for the store and the zero test
    cursor[2] = third;
    cursor[0] = saved;
    // why: 0x21 / 0x25 are the base code plus a 4 offset when third < 4; the key is (first * 4 + second) * 2
    s32 base = (saved * 4 + second) * 2;
    s32 value = base + 0x21;
    if (third < 4) {
        value = base + 0x25;
    }
    if (saved) {
        func_00239bf8((s32)(object + 4), value);
    }
}
