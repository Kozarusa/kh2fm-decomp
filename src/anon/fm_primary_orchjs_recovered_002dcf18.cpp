#include "../common/types.h"
extern "C" u8* func_002dc7c8(s32);
extern "C" f32 D_00349e10;

void func_002dcf18(u8* object) {
    u8* base = object + 0x8000;
    if (base[108] != 0) {
        u8* config = func_002dc7c8((s32)object);
        f32 value = *(f32*)(base + 104);
        if (value < *(f32*)(config + 160)) {
            *(f32*)(base + 104) = value + D_00349e10;
        }
    } else {
        f32 value = *(f32*)(base + 104);
        if (0.0f < value) {
            *(f32*)(base + 104) = value - D_00349e10;
        }
    }
}
