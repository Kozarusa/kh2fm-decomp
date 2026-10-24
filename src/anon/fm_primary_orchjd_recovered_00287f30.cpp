#include "../common/types.h"
extern "C" void func_00106420(u32*);
extern "C" u32* D_0035f324;

void func_00287f30() {
    u32* base = D_0035f324;
    if (base != 0) {
        if ((s32)base != -32) {
            u8* cursor = (u8*)base + 64;
            u8* begin = (u8*)base + 32;
            while (1) {
                asm("" : "+r"(cursor)); // why: keeps the empty element loop the original runs
                if (begin == cursor) {
                    break;
                }
                cursor -= 16;
            }
        }
        func_00106420(base);
        D_0035f324 = 0;
    }
}
