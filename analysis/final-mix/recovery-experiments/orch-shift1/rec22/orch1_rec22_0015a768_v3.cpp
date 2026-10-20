#include "../common/types.h"
extern "C" f32 D_0036b3a8;
extern "C" f32 D_004f3604;
extern "C" u8 D_0034aa70[];
extern "C" void func_00190128(u8*);

void func_0015a768(s32 mode, s64 key) {
    if (key == 0xffff) {
        if (mode == 1) {
            D_004f3604 = D_0036b3a8;
        }
    }
    if (key == 0xffff) {
        if (mode == 1) {
            func_00190128(D_0034aa70);
            // why: original calls with jal and returns normally instead of tail calling
            asm volatile("" ::: "memory");
        }
    }
}