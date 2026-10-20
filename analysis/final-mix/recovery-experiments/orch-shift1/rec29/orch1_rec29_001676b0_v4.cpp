#include "../common/types.h"
extern "C" f32 D_004f526c;
extern "C" f32 D_004f5270;
extern "C" f32 D_00349e10;

void func_001676b0(u64* object, u64 buttons) {
    u64 previous = object[0];
    object[3] = 0;
    object[0] = buttons;
    u64 changed = previous ^ buttons;
    // why: original keeps pressed in t5 so t7 is free for the float address
    register u64 pressed asm("$13") = changed & buttons;
    object[2] = changed & ~buttons;
    object[1] = pressed;
    if (pressed != 0) {
        object[3] = pressed;
        *(f32*)(object + 8) = D_004f526c;
        return;
    }
    if (buttons != 0) {
        f32 timer = *(f32*)(object + 8) - D_00349e10;
        *(f32*)(object + 8) = timer;
        if (timer <= 0.0f) {
            object[3] = buttons;
            *(f32*)(object + 8) = D_004f5270;
        }
    }
}
