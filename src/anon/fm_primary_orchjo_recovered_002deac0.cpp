#include "../common/types.h"
extern "C" f32 D_00375e38;
extern "C" f32 func_001065a8(f32, f32);

f32 func_002deac0(f32* object, f32 first, f32 second) {
    if (first == second) {
        object[6] = first;
    } else {
        object[6] = func_001065a8(first, second);
    }
    register f32* scale asm("$15") = &D_00375e38; // why: original keeps the formed address in t7
    asm("" : "+r"(scale)); // why: keeps the full address formed before the separate lwc1
    object[6] = object[6] * *scale;
    return object[6];
}
