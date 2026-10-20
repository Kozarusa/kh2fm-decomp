#include "../common/types.h"
extern "C" f32 D_0036de10;
extern "C" void func_0017f540(u8*, s32, f32, f32);
extern "C" u32 func_0016bd60(u8*, s32);
extern "C" void func_001c39d0(u32, u32);

void func_001c3aa0(u32 self, u8* object) {
    if (*(f32*)(object + 0x1c) > 0.0f) {
        func_0016bd60(object, 0x12);
        return;
    }
    func_0017f540(object + 0x140, 0xd0, D_0036de10, 0.0f);
    func_001c39d0(self, (u32)object);
}

