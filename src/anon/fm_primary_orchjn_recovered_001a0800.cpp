#include "../common/types.h"
struct Area {
    u8 pad0[4];
    s32 flags;
    u8 pad8[24];
    f32 minX;
    f32 maxX;
    f32 top;
    f32 bottom;
    f32 minZ;
    f32 maxZ;
};
extern "C" f32 func_0016c4e8(void* actor);

s32 func_001a0800(f32 x, f32 y, f32 z, Area* area, void* actor, f32* offset) {
    f32 top = area->top;
    f32 bottom = area->bottom;
    if ((u8)((area->flags >> 1) & 1)) {
        bottom = bottom - func_0016c4e8(actor);
    }
    f32 delta = offset[2];
    if ((u8)((area->flags >> 3) & 1)) {
        top = top - delta;
    } else {
        top = top + delta;
    }
    if ((u8)((area->flags >> 4) & 1)) {
        bottom = bottom + delta;
    } else {
        bottom = bottom - delta;
    }
    s32 result = 0;
    if (area->minX <= x && x < area->maxX && y <= top && bottom < y && z <= area->maxZ && area->minZ < z) {
        result = 1;
    }
    return result;
}
