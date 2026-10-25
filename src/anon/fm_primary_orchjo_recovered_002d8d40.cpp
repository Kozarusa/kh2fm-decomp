#include "../common/types.h"

f32 func_002d8d40(u8* object, f32* first, f32* second) {
              register f32 offset asm("$f2") = 30.0f;     register f32 sum asm("$f1") = *(f32*)(object + 0x1d8) + offset;     asm("" : "+f"(sum));     *first = sum;
    f32 result = *(f32*)(object + 0x1d4) - offset;
    *second = result;
    return result;
}
