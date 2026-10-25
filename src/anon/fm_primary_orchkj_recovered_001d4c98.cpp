#include "../common/types.h"
extern "C" void func_001d1678(u8*, s32);
extern "C" void func_001d19e8(u8*, s32);
extern "C" void func_001d16e8(u8*, s32, s32);
extern "C" u8 D_003525c8[];
extern "C" u8 D_00352750[];

// why: void per DEVIATIONS #36; the only exit is a tail call into the store-only func_001d16e8 (stale-b)

void func_001d4c98(u8* object) {
    *(s32*)(object + 4) = 0;
    *(u8**)object = D_003525c8;
    *(s32*)(object + 8) = 0;
    *(s32*)(object + 12) = 0;
    func_001d1678(object, -1);
    *(s32*)(object + 0x30) = 0;
    *(u8**)object = D_00352750;
    u8* cursor = object + 57;
    s32 count = 127;
    do {
        *cursor = 0;
        count--;
        cursor += 4;
    } while (count >= 0);
    func_001d19e8(object, -1);
    func_001d16e8(object, 0, 12);
}
