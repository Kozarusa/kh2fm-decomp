#include "../common/types.h"

extern "C" u32 func_00198660(...);
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_001d5770(void*, u64);
extern "C" u32 func_0016a9b8(u64);

void func_00198690(s32 object) {
    u32 a, b, c, d;
    u32* source;
    s32 cursor;
    s32 count;
    func_00198660();
    source = (u32*)func_0016c028(object);
    a = source[0];
    b = source[1];
    c = source[2];
    d = source[3];
    cursor = object + 0x9dc;
    count = 1;
    do {
        func_001d5770((void*)cursor, (u64)(s32)&a);
        count = count - 1;
        cursor = cursor + 12;
    } while (count >= 0);
    func_0016a9b8(object);
}
