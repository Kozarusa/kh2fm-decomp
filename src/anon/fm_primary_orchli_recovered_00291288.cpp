#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Object {
    Method* table;
};
extern "C" s32 func_00139d78(u8*);

// why: every exit leaves the last func_00139d78 or method result in v0 (pattern of accepted func_001515b0)

s32 func_00291288(u8* object) {
    s32 result;
    s32 count;
    u8* base;
    base = object;
    count = 4;
    do {
        result = func_00139d78(base + 4);
        if (result) {
            register Method call asm("$14") = ((Object*)(base + 4))->table[5]; // why: original calls the method through t6
            result = call(base + 4);
        }
        result = func_00139d78(base + 2184);
        if (result) {
            register Method call asm("$14") = ((Object*)(base + 2184))->table[5]; // why: original calls the method through t6
            result = call(base + 2184);
        }
        count--;
        base += 436;
    } while (count >= 0);
    base = object;
    count = 14;
    do {
        result = func_00139d78(base + 4364);
        if (result) {
            register Method call asm("$14") = ((Object*)(base + 4364))->table[5]; // why: original calls the method through t6
            result = call(base + 4364);
        }
        count--;
        base += 436;
    } while (count >= 0);
    return result;
}
