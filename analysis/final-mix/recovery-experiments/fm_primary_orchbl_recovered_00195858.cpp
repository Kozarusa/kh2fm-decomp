#include "../common/types.h"

extern "C" u32 func_001ce2d8(u64);
extern "C" u32 func_001ce328(u64);

void func_00195858(u32* object, u64 id) {
    object[7] = func_001ce328(id);
    object[8] = func_001ce2d8(id);
    // why: keeps the reload of object[7] after the store to object[8]
    asm volatile("" ::: "memory");
    f32* source = (f32*)object[7];
    f32* target = (f32*)object;
    target[0] = source[0];
    target[1] = source[1];
    target[2] = source[2];
    target[3] = source[3];
    target[5] = source[8];
    target[6] = source[10];
}
