#include "../common/types.h"
extern "C" f32 D_0036e3c0[];
extern "C" u32 func_00192048(...);

struct Slot {
    s32 handle;
    f32 scaled;
};

void func_001d2690(f32 scale, s32* queue, s32 handle) {
    s32 index = queue[0];
    queue[0] = (index + 1) % 3;
    Slot* slot = (Slot*)(queue + 2) + index;
    slot->handle = func_00192048(handle);
    slot->scaled = scale * D_0036e3c0[0];
}