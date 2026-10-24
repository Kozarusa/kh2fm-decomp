#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_002d10a0(...);

u32 func_002dd790(u8* object) {
    u32 result = func_002d10a0(object);
    register Quad* source asm("$15") = (Quad*)(object + 1344); // why: original keeps the source pointer in t7
    asm("" : "+r"(source)); // why: compiler folds the pointer comparison; original compares at runtime
    object = object + 3056;
    Quad* destination = (Quad*)object;
    if (destination != source) {
        register Quad value asm("$8") = *source; // why: original copies through t0
        asm("" : "+r"(value)); // why: keeps the copy temporary in t0 (pattern of accepted 0013fec0)
        *destination = value;
    }
    return result;
}
