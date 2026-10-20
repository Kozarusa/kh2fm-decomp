#include "../common/types.h"
extern "C" void func_00177a58();
extern "C" u32 func_00187018(f32, u8*, u64, u64, s64);
extern "C" f32 D_0036c4b0[];

void func_00176620(u8* object, u64 second) {
    *(u32*)(object + 0x108) |= 0x2000000;
    func_00177a58();
    volatile f32* pointer = D_0036c4b0;
    func_00187018(*pointer, object, second, 0, -1);
}
