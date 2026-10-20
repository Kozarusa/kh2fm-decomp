#include "../common/types.h"
extern "C" s32 D_01da8cd0[];
extern "C" s32 D_00354690[];
extern "C" void func_001e6648();
extern "C" void func_001e2b68();

void func_001e6688() {
    D_01da8cd0[0] = 0;
    D_01da8cd0[7] = 0;
    D_00354690[0] = 0;
    D_00354690[1] = -1;
    D_01da8cd0[1] = 0;
    D_01da8cd0[5] = 0;
    D_01da8cd0[4] = 0;
    D_01da8cd0[2] = 0;
    D_01da8cd0[6] = 0;
    D_01da8cd0[3] = 0;
    func_001e6648();
    func_001e2b68();
    asm volatile("" ::: "memory"); // why: original uses jal plus return, not a tail jump
}