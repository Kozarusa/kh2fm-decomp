#include "../common/types.h"

extern "C" f32 D_0036c9a8[];
extern "C" u32 func_001dc978(s32, f32);
extern "C" s32 func_001de168(s32, s32, s32, s32, s32, s32);

void func_001877a0(u8* object, s32 first, s32 second) {
    s32 effect = *(s32*)(object + 2784);
    if (effect != 0) {
        f32* pointer = D_0036c9a8;
        // why: keeps the address materialized before the load, as in the original
        asm("" : "+r"(pointer));
        func_001dc978(effect, *pointer);
    }
    *(s32*)(object + 2784) = func_001de168(first, second, 0, 1, 10000, (s32)object);
}
