#include "../common/types.h"
extern "C" u8 D_00371698[];
extern "C" u32 func_002ff2e8(u8*, u8*);
extern "C" s32 func_002ff3fc(u8*);
// why: no recovered source calls this function; parameters derived from a0-a2 set before the jal, result unused here
extern "C" void func_00240118(u8*, s32, s32);

u32 func_00240240(u8* destination, s32 value, s32 mode) {
    u8 buffer[80];
    u32 result;
    s32 index;

    func_002ff2e8(buffer, D_00371698);
    func_00240118(buffer + func_002ff3fc(buffer), value, mode);
    register s32 length asm("$18") = func_002ff3fc(buffer); // why: original keeps the length in s2, separate from the s0/s1 parameter copies
    for (index = 0; index < 2; index++) {
        result = func_002ff2e8(destination + index * length, buffer);
    }
    return result;
}
