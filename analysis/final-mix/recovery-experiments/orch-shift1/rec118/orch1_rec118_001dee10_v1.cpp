#include "../common/types.h"
extern "C" void func_001e0158(...);
extern "C" void func_001e01b8(u32);

void func_001dee10(s32 object) {
    if ((*(u32*)(object + 0x5c) & 4) != 0) {
        s32 pointer = *(s32*)(object + 0x58);
        if (pointer != 0) {
            // why: original keeps the counter in t7
            register s32 end asm("$15") = pointer + 0x40;
            // why: original keeps the fixed compare value in t6
            register s32 base asm("$14") = pointer + 0x20;
            bool more;
            if (pointer != -0x20) {
                do {
                    more = base != end;
                    end = end - 0x10;
                } while (more);
            }
            func_001e0158();
            asm volatile("" ::: "memory");
        }
    } else {
        if ((*(u32*)(object + 0x5c) & 8) != 0) {
            func_001e01b8(*(u32*)(object + 0x58));
            asm volatile("" ::: "memory");
        }
    }
}
