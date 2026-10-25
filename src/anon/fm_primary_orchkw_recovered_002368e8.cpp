#include "../common/types.h"
struct Object002368e8 {
    u8 pad0[0x24];
    s32 width;
    s32 height;
    u8 pad2c[4];
    s32 busy;
    u8 pad34[8];
    u32* colors;
    u8 pad40[0x158];
    s8* done;
};
// why: no recovered source calls or defines this callee; the color word comes from a0 and
// the factor from $f12, and the caller stores the v0 result back into the color array
extern "C" u32 func_001319d8(u32 color, f32 factor);

void func_002368e8(Object002368e8* object, f32 factor) {
    if (*object->done == 0 && object->busy == 0) {
        s32 count = object->width * object->height;
        u32* colors = object->colors;
        while (count > 0) {
            count--;
            *colors = func_001319d8(*colors, factor);
            colors++;
        }
        *object->done = 1;
    }
}
