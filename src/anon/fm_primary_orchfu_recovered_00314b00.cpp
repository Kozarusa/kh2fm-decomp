#include "../common/types.h"

u8* func_00314b00(u8* cursor, u64* out) {
    u32 shift = 0;
    u64 accum = 0;
    u32 byte;
    do {
        byte = *cursor;
        cursor = cursor + 1;
        u32 part = byte & 0x7f;
        u32 moved;
        asm("sllv %0,%1,%2" : "=r"(moved) : "r"(part), "r"(shift)); // why: native shift wraps the count, no mask emitted
        accum = (s64)(s32)moved | accum;
        shift = shift + 7;
    } while ((byte & 0xffffff80) != 0);
    *out = accum;
    return cursor;
}
