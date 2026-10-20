#include "../common/types.h"
extern "C" s16 D_0035f4e0;
extern "C" s32* D_0035f4dc;
void func_002930d8(void) {
    register s16* count asm("$11") = &D_0035f4e0; // why: original keeps count address in t3 across loop
    if (*count != 0) {
        if (*count > 1) {
            s32 index = 1;
            if (index < *count) {
                do {
                    s32* pointer = D_0035f4dc + index;
                    ++index;
                    pointer[-1] = *pointer;
                    asm volatile("" ::: "memory"); // why: keeps store order before count and pointer reloads
                } while (index < *count);
            }
        }
        --*count;
    }
}


