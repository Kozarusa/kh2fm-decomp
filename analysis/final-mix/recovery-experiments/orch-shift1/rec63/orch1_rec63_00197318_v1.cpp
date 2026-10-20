#include "../common/types.h"

extern "C" u32 func_00170320(s32);
extern "C" void func_00196e88(f32, u32, s32, s32);

void func_00197318(u32* object) {
    u32 flags;
    s32 mode;
    func_00170320(2000);
    flags = *object;
    mode = 3;
    *object = flags | 1;
    if (((*(u16*)(object[15] + 2) >> 1) & 1) == 0) {
        *object = flags | 3;
        mode = 4;
    }
    func_00196e88(0.0f, (u32)object, mode, 0);
}
