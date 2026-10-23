#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Object {
    Method* table;
};
extern "C" u32 func_00139510(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0031a260(...);

s32 func_001506e0(u8* object) {
    s32 result;
    s32 count;
    u8* entry;
    u8* base;
    if (func_00139d78(object)) {
        register Method method asm("$15") = ((Object*)object)->table[5]; // why: original calls the method through t7
        method(object);
    }
    if (func_00139d78(object + 48)) {
        func_00139510(object + 48);
    }
    base = object;
    count = 12;
    entry = object + 840;
    do {
        result = func_00139d78(entry);
        if (result) {
            *(s32*)(base + 1236) = 0;
            func_001396b0(entry);
            if (*(s32*)(base + 1236)) {
                *(s32*)(base + 1240) = 0;
                func_001396b0(entry);
                if (*(s32*)(base + 1240)) {
                    func_0031a260(entry, 0);
                }
            }
            register Method call asm("$15") = ((Object*)(base + 840))->table[5]; // why: original calls the method through t7
            result = call(entry);
        }
        base += 408;
        count--;
        entry += 408;
    } while (count >= 0);
    return result;
}
