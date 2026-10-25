#include "../common/types.h"
extern "C" u16 D_00373a88[];
extern "C" u8* func_00257770(void);
extern "C" u64 func_00257140(s32);
extern "C" void func_00138c10(s32, u64);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_00257070(s32);

// why: every exit returns a live callee v0 (func_00257070 when zero, else the last func_00192048 result), so the result is returned

u32 func_00272938(void) {
    // why: original keeps the loop counter in s1 and the table cursor in s2
    register s32 count asm("$17") = 1;
    u8* list = func_00257770();
    u8* entry = list + 0x60a4;
    u16* table = D_00373a88;
    u32 result;
    do {
        count--;
        func_00138c10((s32)entry, func_00257140(0));
        result = func_00192048(*table);
        table++;
        *(u32*)(entry + 408) = result;
        entry += 436;
    } while (count >= 0);
    result = func_00257070(25);
    if (result != 0) {
        entry = list + 0x640c;
        table = D_00373a88;
        count = 1;
        do {
            count--;
            func_00138c10((s32)entry, func_00257140(0));
            result = func_00192048(*table);
            table++;
            *(u32*)(entry + 408) = result;
            entry += 436;
        } while (count >= 0);
    }
    return result;
}
