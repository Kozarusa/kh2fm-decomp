#include "../common/types.h"

// Preserve original registry aliases.
void func_00188b68(s32 pointer, s32 value, u8 flag) asm("_ZN2YS7PARTRAM11add_abilityEib");

void func_00188b68(s32 pointer, s32 value, u8 flag) {
    s32 index;
    register u32 low asm("$13") = value & 0x7fff; // why: original keeps the low bits in t5
    register u32 high asm("$5") = (flag != 0); // why: original keeps the flag bit in a1
    high = high << 15;

    pointer = pointer + 0x50;
    index = 0;
    do {
        if ((*(u16*)(pointer + 4) & 0x7fff) == 0) {
            asm("" : "+r"(low)); // why: keeps the or inside the found-slot block instead of hoisting it before the loop
            register u32 result asm("$15") = low | high; // why: original forms the slot value in t7
            *(u16*)(pointer + 4) = result;
            return;
        }
        index = index + 1;
        pointer = pointer + 2;
    } while (index < 0x50);
}
