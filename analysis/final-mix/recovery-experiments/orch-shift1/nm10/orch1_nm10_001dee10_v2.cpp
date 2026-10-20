#include "../common/types.h"
extern "C" void func_001e0158(s32);
extern "C" void func_001e01b8(u32);

void func_001dee10(s32 object) {
    if ((*(u32*)(object + 0x5c) & 4) != 0) {
        s32 pointer = *(s32*)(object + 0x58);
        if (pointer != 0) {
            s32 end = pointer + 0x40;
            if (pointer != -0x20) {
                // why: original keeps the fixed compare base in t6 ($14)
                register s32 base asm("$14") = pointer + 0x20;
                // why: original compares the counter in t7 ($15) before the decrement
                register s32 previous asm("$15");
                do {
                    previous = end;
                    end = end - 0x10;
                } while (base != previous);
            }
            func_001e0158(pointer);
            asm volatile("" ::: "memory");
        }
    } else {
        if ((*(u32*)(object + 0x5c) & 8) != 0) {
            func_001e01b8(*(u32*)(object + 0x58));
            asm volatile("" ::: "memory");
        }
    }
}
