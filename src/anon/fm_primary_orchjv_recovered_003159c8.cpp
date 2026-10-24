#include "../common/types.h"

typedef s32 (*Callback)(u32*);

s32 func_003159c8(u32* object, u32 unused, u32 left, u32* other, u32 right) {
    if (right == left) {
        register u32 objectValue asm("$14") = object[1]; // why: library code loads the object field first into t6
        asm volatile("" ::: "memory"); // why: keeps load order (object field before other field)
        register u32 otherValue asm("$15") = other[1]; // why: library code loads the other field second into t7
        if (objectValue == otherValue) {
            return 6;
        }
    }
    u32* receiver = (u32*)object[2];
    u32* table = *(u32**)receiver;
    Callback call = (Callback)table[8];
    return call(receiver);
}
