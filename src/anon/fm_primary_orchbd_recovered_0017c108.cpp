#include "../common/types.h"
extern "C" f32 D_0036c500;
extern "C" void func_0017f540(u8*, s32, f32, f32);

void func_0017c108(s32 unused, u8* object, s32 mode) {
    u8* target = object + 0x140;
    u32 flags = *(u32*)(object + 0x160);
    if ((flags & 4) == 0) {
        if ((flags & 0x10) == 0 || mode == 0) {
            return;
        }
    }
    // why: sibling 00176818 pins the global address in $15 so lwc1 uses offset 0
    register f32* coefficient asm("$15") = &D_0036c500;
    asm("" : "+r"(coefficient));
    func_0017f540(target, mode, *coefficient, 0.0f);
}
