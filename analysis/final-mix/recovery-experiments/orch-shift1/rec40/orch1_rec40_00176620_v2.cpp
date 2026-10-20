#include "../common/types.h"
extern "C" void func_00177a58();
extern "C" u32 func_00187018(f32, u64, u64, u64, s64);
extern "C" f32 D_0036c4b0[];

void func_00176620(u64 object, u64 second) {
    *(u32*)((s32)object + 0x108) |= 0x2000000;
    func_00177a58();
    func_00187018(D_0036c4b0[0], object, second, 0, -1);
}
