#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" f32 D_0036d7a4;
s32 func_001ad9c8(f32* object) {
    if (object[1] == 0.0f) return 0;
    f32 value = object[0] + object[1] * D_00349e10;
    object[0] = value;
    if (value <= 0.0f) {
        object[0] = 0.0f;
        object[1] = 0.0f;
    } else {
        // why: materializes the limit address in the original integer register.
        register f32* pointer asm("$15") = &D_0036d7a4;
        // why: preserves address materialization before the float load.
        asm("" : "+r"(pointer));
        f32 limit = *pointer;
        if (!(limit <= value)) return 1;
        object[1] = 0.0f;
        object[0] = limit;
    }
    return 1;
}


