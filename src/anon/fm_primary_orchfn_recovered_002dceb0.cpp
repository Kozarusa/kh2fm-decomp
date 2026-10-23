#include "../common/types.h"
extern "C" u8* func_002dc7c8(void);
extern "C" f32 D_00375dac;

f32 func_002dceb0(u8* object) {
    u8* base = object + 0x8000;
    u8* other = func_002dc7c8();
    f32 value = *(f32*)(base + 104) / *(f32*)(other + 160);
    // why: original materializes the limit address in t7 ($15) before the divide
    register f32* limit_pointer asm("$15") = &D_00375dac;
    // why: keeps the address materialized in t7 before the divide
    asm("" : "+r"(limit_pointer));
    f32 limit = *limit_pointer;
    if (limit < value) {
        value = limit;
    }
    if (value < 0.0f) {
        value = 0.0f;
    }
    return value;
}
