#include "../common/types.h"
extern "C" void func_00196e88(f32, u32, s32, s32);

void func_001973f0(u32 object) {
    u8 flag = *(u16*)(*(u32*)(object + 0x3c) + 2) & 1;
    s32 mode;
    if (flag == 0) {
        mode = 0;
    } else {
        mode = 2;
    }
    func_00196e88(0.0f, object, 6, mode);
}