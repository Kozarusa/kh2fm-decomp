#include "../common/types.h"
extern "C" bool func_002282f0(...);
extern "C" u32 func_00227d10(...);
u32 func_0022efb8(u8* object) {
    u32 result = func_002282f0(*(s16*)(object + 4));
    if (result == 0) {
        result = func_00227d10(*(s16*)(object + 12));
        u8* pointer = (u8*)result;
        register s32 value asm("$14") = *(s16*)(object + 4); // why: original initial halfword uses t6
        asm("" : "+r"(value)); // why: keeps initial halfword in original t6
        *(s32*)(pointer + 12) = value;
        asm volatile("" ::: "memory"); // why: keeps store order
        *(s32*)(pointer + 16) = *(s16*)(object + 4) + *(s16*)(object + 10);
        pointer[20] = object[8];
        pointer[21] = object[9];
    }
    return result;
}
