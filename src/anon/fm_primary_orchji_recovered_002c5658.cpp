#include "../common/types.h"

extern "C" f32 D_00375750[];
extern "C" u32 func_001dc978(s32, f32);
extern "C" s32 func_001de168(s32, s32, s32, s32, s32, s32);

s32 func_002c5658(u8* object, s32 first, s32 second) {
    s32 effect = *(s32*)(object + 2552);
    if (effect != 0) {
        f32* pointer = D_00375750;
        // why: keeps the address materialized before the load, as in the original
        asm("" : "+r"(pointer));
        func_001dc978(effect, *pointer);
    }
    s32 result = func_001de168(first, second, 0, 1, 40001, (s32)object);
    *(s32*)(object + 2552) = result;
    return result;
}
