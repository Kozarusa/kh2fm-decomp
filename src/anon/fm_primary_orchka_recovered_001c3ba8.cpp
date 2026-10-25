#include "../common/types.h"
struct __attribute__((aligned(16))) Vec4 {
    f32 x; f32 y; f32 z; f32 w;
};
struct Params {
    u8 pad[36];
    f32 scale;
    f32 offset;
    f32 limit;
};
extern "C" Vec4* func_0016c028(s32);
extern "C" f32 func_00184a90(s32);

// why: a0 is never read; the object arrives in a1

f32 func_001c3ba8(s32 unused, s32 object) {
    f32 height;
    if (0.0f < func_00184a90(object) - func_0016c028(object)->y) {
        height = func_00184a90(object) - func_0016c028(object)->y;
    } else {
        height = 0.0f;
    }
    f32 distance;
    if (0.0f < height - (*(Params**)(object + 240))->offset) {
        f32 inner;
        if (0.0f < func_00184a90(object) - func_0016c028(object)->y) {
            inner = func_00184a90(object) - func_0016c028(object)->y;
        } else {
            inner = 0.0f;
        }
        distance = inner - (*(Params**)(object + 240))->offset;
    } else {
        distance = 0.0f;
    }
    Params* params = *(Params**)(object + 240);
    f32 value = distance * params->scale;
    f32 limit = params->limit;
    return value < limit ? value : limit;
}
