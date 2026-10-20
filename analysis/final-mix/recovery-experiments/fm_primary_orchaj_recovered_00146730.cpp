#include "../common/types.h"
extern "C" void func_00144b38(u32, u8*);
extern "C" void func_001466b0(u32, u8*);

void func_00146730(u32 object, u32 other) {
    u8 buffer[128];
    func_00144b38(other, buffer);
    func_001466b0(object, buffer);
    u8* cursor = buffer + 128;
    while (1) {
        // why: original loop body is five nop words
        asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
        if (buffer == cursor) break;
        cursor -= 16;
    }
}
