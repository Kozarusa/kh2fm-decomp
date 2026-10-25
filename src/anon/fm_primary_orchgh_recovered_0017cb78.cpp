#include "../common/types.h"
extern "C" void func_0017f488(s32, s32, f32, f32);
extern "C" void func_00180c88(s32, s32, f32);

void func_0017cb78(s32 unused, u8* object) {
    s32 mode = *(s32*)(object + 0x100);
    if (mode == 4) {

                 func_0017f488((s32)(object + 0x140), 4, 8.0f, 0.0f);
    } else if (mode >= 0) {

                 func_00180c88((s32)(object + 0x140), mode, 8.0f);
    }
    *(u32*)(object + 0x10c) = *(u32*)(object + 0x10c) & 0xfffffffe;
}
