#include "../common/types.h"
extern "C" void func_001d7b10();

// Preserve original registry aliases.
void func_001d7a08(s32 object, s32 value) asm("_Z16wtarget_001d7a08jjjj");

void func_001d7a08(s32 object, s32 value) {
    // why: original keeps the cursor in t6 and the counter in t5
    register s32 *entry asm("$14") = (s32*)object;
    // why: counter lives in t5 ($13) in the original
    register s32 count asm("$13") = 3;
    do {
        s32 item = entry[1];
        count--;
        if (item == value) {
            entry[1] = 0;
            func_001d7b10();
            return;
        }
        entry += 2;
    } while (count >= 0);
}
