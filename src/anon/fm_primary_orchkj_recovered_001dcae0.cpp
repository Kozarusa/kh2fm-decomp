#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" f32* func_001dc670();
extern "C" u64 func_001dc878(...);

void func_001dcae0(u8* object) {
    f32 speed = *(f32*)(object + 36);
    if (speed != 0.0f) {
        f32 value = *(f32*)(object + 32) + speed * D_00349e10;
        *(f32*)(object + 32) = value;
        if (value < 0.0f) {
            *(f32*)(object + 32) = 0.0f;
            *(f32*)(object + 36) = 0.0f;
        }
        if (0.0f < *(f32*)(object + 32)) {
            f32* color = func_001dc670();
            color[3] = color[3] * *(f32*)(object + 32);
        }
    }
    if ((*(u32*)(object + 8) & 0x20000) != 0 && *(f32*)(object + 32) <= 0.0f) {
        // why: tail call into func_001dc878, whose accepted definition (fm_scalar_recovered_05.cpp) is void; its v0 is stale (ruling #36 stale-b), so it is not returned
        func_001dc878(object);
    }
}
