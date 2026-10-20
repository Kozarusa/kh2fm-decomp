#include "../common/types.h"
extern "C" f32 D_0036c544[];
extern "C" f32 D_0036c548[];
extern "C" f32 func_002f8b00(f32, f32);

f32 func_0017ce10(f32 value) {
    f32 offset;
    f32 *pointer;
    if (0.0f < value) {
        pointer = D_0036c544;
        // why: forces separate lui/addiu address materialization
        asm("" : "+r"(pointer));
        offset = *pointer;
        pointer = D_0036c548;
        // why: forces separate lui/addiu address materialization
        asm("" : "+r"(pointer));
        f32 result = func_002f8b00(value + offset, *pointer);
        return result - offset;
    } else {
        pointer = D_0036c544;
        // why: forces separate lui/addiu address materialization
        asm("" : "+r"(pointer));
        offset = *pointer;
        pointer = D_0036c548;
        // why: forces separate lui/addiu address materialization
        asm("" : "+r"(pointer));
        f32 result = func_002f8b00(offset - value, *pointer);
        return offset - result;
    }
}
