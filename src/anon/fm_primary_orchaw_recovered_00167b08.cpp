#include "../common/types.h"
extern "C" u8 D_0034d3c0[];
extern "C" void func_00167ad0(u8*, u32);

// Preserve original registry aliases.
void func_00167b08(u32 value) asm("_Z16u_call4_00167b08jjjj");

void func_00167b08(u32 value) {
    s32 pointer = (s32)D_0034d3c0;
    s32 end = pointer + 0x300;
    do {
        func_00167ad0((u8*)pointer, value);
        pointer = pointer + 0x180;
    } while (pointer < end);
}
