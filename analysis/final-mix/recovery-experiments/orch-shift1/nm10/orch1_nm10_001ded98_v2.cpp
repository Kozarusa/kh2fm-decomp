#include "../common/types.h"
extern "C" void func_001e0158(...);
extern "C" void func_001e01b8(u32);

void func_001ded98(s32 object) {
    if ((*(u32*)(object + 0x5c) & 4) != 0) {
        s32 pointer = *(s32*)(object + 0x58);
        if (pointer != 0) {
            // why: original keeps the loop counter in t7 ($15)
            register s32 end asm("$15") = pointer + 0x40;
            bool more;
            if (pointer != -0x20) {
                do {
                    more = pointer + 0x20 != end;
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
