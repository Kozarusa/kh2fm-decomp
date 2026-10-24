#include "../common/types.h"

s32 func_00146ed8(s32 unused, u8* object) {
    u32 state = object[0xeb];
    asm("" : "+r"(state)); // why: original re-masks the loaded byte with andi 0xff before the zero test
    register s32 sign asm("$14") = (s8)state; // why: original keeps the sign-extended byte in t6
    u32 value;
    if ((u8)state != 0) {
        if (sign >= 0) {
            value = *(u32*)(object + 0xf8);
            if ((value & 0x10) != 0) {
                *(u32*)(object + 0xf8) = value & ~0x800;
                return 1;
            }
        } else {
            value = *(u32*)(object + 0xf8);
        }
    } else {
        value = *(u32*)(object + 0xf8);
    }
    *(u32*)(object + 0xf8) = value | 0x800;
    return 0;
}
