#include "../common/types.h"
extern "C" void func_00196e88(f32, u32, s32, u64);

void func_001973f0(u32 object) {
    u64 mode;
    u8 flag = *(volatile u16*)(*(u32*)(object + 0x3c) + 2) & 1;
    if (flag == 0) {
        mode = 0;
    } else {
        mode = 2;
    }
    func_00196e88(0.0f, object, 6, mode);
}