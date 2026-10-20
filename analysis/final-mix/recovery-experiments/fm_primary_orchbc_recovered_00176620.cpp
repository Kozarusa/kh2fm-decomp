#include "../common/types.h"
extern "C" void func_00177a58();
extern "C" u32 func_00187018(f32, u8*, u64, u64, s64);
extern "C" u8 D_0036c4b0[];

void func_00176620(u8* object, u64 second) {
    *(u32*)(object + 0x108) |= 0x2000000;
    func_00177a58();
    u8* pointer = D_0036c4b0;
    // why: keeps the address formed in a register before the float load
    asm("" : "+r"(pointer));
    func_00187018(*(f32*)pointer, object, second, 0, -1);
}
