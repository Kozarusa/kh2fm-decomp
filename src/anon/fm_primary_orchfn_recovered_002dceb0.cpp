#include "../common/types.h"
extern "C" u8* func_002dc7c8(void);

f32 func_002dceb0(u8* object) {
    u8* base = object + 0x8000;
    u8* other = func_002dc7c8();
    f32 value = *(f32*)(base + 104) / *(f32*)(other + 160);

    f32 limit = 1.0f;
    if (limit < value) {
        value = limit;
    }
    if (value < 0.0f) {
        value = 0.0f;
    }
    return value;
}
