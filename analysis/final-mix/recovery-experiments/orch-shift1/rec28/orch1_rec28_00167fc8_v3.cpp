#include "../common/types.h"
extern "C" s32 D_004f5250;
extern "C" s32 D_0034d780;
extern "C" s32 D_004f5258[];
extern "C" void func_00167f38();

void func_00167fc8(void) {
    s32 value = D_004f5250;
    s32 index = D_0034d780;
    D_004f5258[index] = value;
    asm volatile("" ::: "memory"); // why: keeps store order
    D_0034d780 = index + 1;
    func_00167f38();
}
