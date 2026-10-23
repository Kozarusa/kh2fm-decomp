#include "../common/types.h"

extern "C" s32 D_0034ed00;
extern "C" s32 D_01c60588[];
extern "C" void func_0019a308(s32);

void func_00182f38(void) {
    s32 index = 0;
    if (D_0034ed00 > 0) {
        s32* base = D_01c60588;
        // why: keeps the table base in its own register before the +8 field offset is added
        asm("" : "+r"(base));
        s32* entry = base + 2;
        do {
            index++;
            func_0019a308(*entry);
            entry += 3;
        } while (index < D_0034ed00);
    }
}
