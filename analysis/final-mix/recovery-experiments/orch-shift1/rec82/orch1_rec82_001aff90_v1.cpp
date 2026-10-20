#include "../common/types.h"
extern "C" u8* D_01c940b4;

u8* func_001aff90(u32 first, u32 second) {
    s32 index = 0;
    u8* pointer = D_01c940b4 + 8;
    s32 count = *(s32*)(D_01c940b4 + 4);
    if (count > 0) {
        do {
            if (pointer[0] == first && pointer[1] == second) {
                return pointer;
            }
            index++;
            pointer += 14;
        } while (index < count);
    }
    return 0;
}
