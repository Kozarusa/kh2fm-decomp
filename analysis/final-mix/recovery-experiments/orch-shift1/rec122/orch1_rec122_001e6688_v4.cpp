#include "../common/types.h"
extern "C" volatile s32 D_01da8cd0; // why: keeps store order
extern "C" volatile s32 D_00354690; // why: keeps store order
extern "C" void func_001e6648();
extern "C" void func_001e2b68();

void func_001e6688() {
    volatile s32* base = &D_01da8cd0; // why: keeps store order
    volatile s32* other = &D_00354690; // why: keeps store order
    D_01da8cd0 = 0;
    base[7] = 0;
    D_00354690 = 0;
    other[1] = -1;
    base[1] = 0;
    base[5] = 0;
    base[4] = 0;
    base[2] = 0;
    base[6] = 0;
    base[3] = 0;
    func_001e6648();
    func_001e2b68();
    asm volatile("" ::: "memory"); // why: original uses jal plus return, not a tail jump
}