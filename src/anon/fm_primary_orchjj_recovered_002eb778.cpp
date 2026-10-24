#include "../common/types.h"
extern "C" void func_002eb6f8(f32, u32, s32);

void func_002eb778(f32 blend, u32 object, s32 value, u8 force) {
    if (force == 0) {
        u32 flags = *(u32*)(object + 0x160);
        u32 mode = flags;
        u32 active = (flags & 4) != 0 || (mode & 8) != 0 || (flags & 0x10) != 0;
        if ((u8)active == 0) {
            if ((flags & 0x10) == 0) {
                return;
            }
        }
        if (*(s32*)(object + 0x154) == value) {
            return;
        }
    }
    func_002eb6f8(blend, object, value);
}
