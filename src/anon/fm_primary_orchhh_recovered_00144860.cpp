#include "../common/types.h"

// Preserve original registry aliases.
void func_00144860(f32* result, f32* first, f32* second) asm("_Z13func_00144860Pv");

void func_00144860(f32* result, f32* first, f32* second) {
    f32 a;
    a = first[0];
    f32 b0 = second[0];
    f32 value0 = (a < b0) ? a : b0;
    a = first[1];
    f32 b1 = second[1];
    result[0] = value0;
    f32 value1 = (a < b1) ? a : b1;
    a = first[2];
    f32 b2 = second[2];
    result[1] = value1;
    f32 value2 = (a < b2) ? a : b2;
    a = first[3];
    f32 b3 = second[3];
    result[2] = value2;
    f32 value3 = (b3 < a) ? a : b3;
    a = first[4];
    f32 b4 = second[4];
    result[3] = value3;
    f32 value4 = (b4 < a) ? a : b4;
    a = first[5];
    f32 b5 = second[5];
    result[4] = value4;
    f32 value5 = (b5 < a) ? a : b5;
    result[5] = value5;
}
