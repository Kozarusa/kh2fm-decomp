#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" u32 func_001dc840(s32);

void func_00176c68(u8 *object) {
    s32 effect = *(s32 *)(object + 0xae4);
    if (effect != 0) {
        f32 timer = *(f32 *)(object + 0xae8) - D_00349e10;
        *(f32 *)(object + 0xae8) = timer;
        if ((*(u32 *)(object + 0x160) & 0x4000) != 0 || timer <= 0.0f) {
            func_001dc840(effect);
            *(s32 *)(object + 0xae4) = 0;
        }
    }
}