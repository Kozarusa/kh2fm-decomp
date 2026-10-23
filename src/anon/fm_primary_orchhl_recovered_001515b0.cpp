#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Object {
    Method* table;
};
extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);

s32 func_001515b0(u8* object) {
    s32 result;
    s32 count;
    u8* base;
    if (func_00139d78(object)) {
        register Method method asm("$15") = ((Object*)object)->table[5]; // why: original calls the method through t7
        method(object);
    }
    if (func_00139d78(object + 48)) {
        func_00139510(object + 48);
    }
    base = object;
    count = 9;
    do {
        result = func_00139d78(base + 496);
        if (result) {
            register Method call asm("$14") = ((Object*)(base + 496))->table[5]; // why: original calls the method through t6
            result = call(base + 496);
        }
        count--;
        base += 408;
    } while (count >= 0);
    base = object;
    count = 3;
    do {
        result = func_00139d78(base + 4576);
        if (result) {
            register Method call asm("$14") = ((Object*)(base + 4576))->table[5]; // why: original calls the method through t6
            result = call(base + 4576);
        }
        count--;
        base += 408;
    } while (count >= 0);
    return result;
}
