#include "../common/types.h"
extern "C" u8* D_0035f610;

// Argument domain: value is a 32-bit signed flag index. The EABI keeps s32 values
// sign-extended in their 64-bit register, so the entry bgez on a0 is the s32 sign
// test; a negative value means "any of the 96 flags", a non-negative one selects
// one flag and only its low 32 bits are used (srl/andi). Same domain as the
// accepted siblings func_002aacd8, func_002aaa38 and func_002aa2f8.

s32 func_002ab100(s32 value) {
    if (value < 0) {
        u32 index = 0;
        u32* pointer = (u32*)(D_0035f610 + 0x88);
        s32 result;
        do {
            u32 mask = 1u << (index & 31);
            result = (pointer[index >> 5] & mask) != 0;
            ++index;
        } while (!result && (s32)index < 0x60);
        return result;
    }
    u32 mask = 1u << ((u32)value & 31);
    u8* pointer = D_0035f610 + ((u32)value >> 5) * 4;
    return (*(u32*)(pointer + 0x88) & mask) != 0;
}
