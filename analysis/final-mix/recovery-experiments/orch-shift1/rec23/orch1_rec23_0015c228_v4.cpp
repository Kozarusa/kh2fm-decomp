#include "../common/types.h"
extern "C" u32 D_0034af20;
extern "C" u32 D_0034af24;
extern "C" s64 D_0034af30;

void func_0015c228(u32* data) {
    if (data == 0) {
        D_0034af24 = 0;
        D_0034af20 = 0;
        return;
    }
    D_0034af20 = (u32)data + data[0];
    u32 count = data[1] / 104;
    D_0034af30 = 0;
    asm("" : "+r"(count)); // why: keeps the quotient live across the store so the address register changes
    D_0034af24 = count;
}
