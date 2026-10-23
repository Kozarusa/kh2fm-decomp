#include "../common/types.h"
extern "C" void func_001e0158(s32);
extern "C" void func_001e01b8(u32);

void func_001ded98(s32 object) {
    if ((*(u32*)(object + 0x5c) & 4) != 0) {
        s32 pointer = *(s32*)(object + 0x58);
        if (pointer != 0) {
            s32 previous;
            if (pointer != -0x20) {
                // why: original keeps the loop counter in t7 ($15)
                register s32 end asm("$15") = pointer + 0x40;
                // why: original keeps the fixed compare base in t6 ($14)
                register s32 base asm("$14") = pointer + 0x20;
                for (;; end -= 0x10) {
                    if (base == end) break;
                }
            }
            func_001e0158(pointer);
            asm volatile("" ::: "memory"); // why: preserve original non-tail call epilogue
        }
    } else {
        if ((*(u32*)(object + 0x5c) & 8) != 0) {
            func_001e01b8(*(u32*)(object + 0x58));
            asm volatile("" ::: "memory"); // why: preserve original non-tail call epilogue
        }
    }
}
