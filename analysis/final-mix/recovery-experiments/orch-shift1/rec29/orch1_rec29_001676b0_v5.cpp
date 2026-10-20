#include "../common/types.h"
extern "C" f32 D_004f526c;
extern "C" f32 D_004f5270;
extern "C" f32 D_00349e10;

void func_001676b0(u64* object, u64 buttons) {
    u64 previous = object[0];
    object[3] = 0;
    object[0] = buttons;
    u64 changed = previous ^ buttons;
    u64 pressed = changed & buttons;
    object[2] = changed & ~buttons;
    object[1] = pressed;
    f32 initial = D_004f526c;
    if (pressed != 0) {
        object[3] = pressed;
        *(f32*)(object + 8) = initial;
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
