#include "../common/types.h"
extern "C" bool func_0019ba60(...);
extern "C" u16 func_0016a070(...);
extern "C" u32 func_00198630(...);
extern "C" u32 func_001afe70(...);

void func_00176cd0(int object, u32 value, u32 extra)
{
    s32 result;
    u32 part;
    u32 other;
    u32 buffer[4];

    buffer[0] = extra;
    if (*(int *)(object + 0x9b8) != 0) {
        result = func_0019ba60(*(u32 *)(object + 0x9f4)); asm volatile("" ::: "memory"); // why: keeps call ordering
        other = 0;
        if ((result != 0) && (*(int *)(object + 0x9f4) != object)) {
            other = func_0016a070(*(int *)(object + 0x9f4)); asm volatile("" ::: "memory"); // why: keeps call ordering
        }
        part = func_0016a070(object); asm volatile("" ::: "memory"); // why: keeps call ordering
        result = func_001afe70(part, value, other, buffer); asm volatile("" ::: "memory"); // why: keeps call ordering
        if (-1 < result) {
            func_00198630(object, result, buffer[0]); asm volatile("" ::: "memory"); // why: keeps call ordering
        }
    }
    return;
}
