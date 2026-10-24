#include "../common/types.h"
extern "C" s32 D_0036c5b8[];
extern "C" s32 D_0036c5cc[];
extern "C" u32 func_0017ebc8(...);
extern "C" u32 func_001a97b8(...);
extern "C" u32 func_00180408(...);

// Preserve original registry aliases.
u32 func_00180828(s32* object) asm("_Z16wtarget_00180828jjjj");

u32 func_00180828(s32* object) {
    if (*object != 0) {
        s32* table;
        if (func_0017ebc8() != 0) {
            table = D_0036c5b8;
        } else {
            table = D_0036c5cc;
        }
        s32 value;
        while ((value = *table++) >= 0) {
            u32 result = func_001a97b8(*object, value);
            if (result != 0) {
                return func_00180408(object, result);
            }
        }
    }
    return 0;
}
