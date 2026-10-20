#include "../common/types.h"

extern "C" u32 func_00198660(...);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001d5770(void*, u64);
extern "C" u32 func_0016a9b8(u64);

void func_00198690(u32 object) {
    u32* source;
    s32 cursor;
    s32 count;
    u32 a, b, c, d;
    func_00198660(); asm volatile("" ::: "memory"); // why: keeps call order and values live across calls
    source = (u32*)func_0016c028(object); asm volatile("" ::: "memory"); // why: keeps call order
    a = source[0];
    b = source[1];
    c = source[2];
    d = source[3];
    cursor = (s32)object + 0x9dc;
    count = 1;
    do {
        func_001d5770((void*)cursor, (u64)(u32)&a); asm volatile("" ::: "memory"); // why: keeps call order
        count = count - 1;
        cursor = cursor + 12;
    } while (-1 < count);
    func_0016a9b8(object); asm volatile("" ::: "memory"); // why: keeps call order
}
