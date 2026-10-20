#include "../common/types.h"

extern "C" u64 D_01da8bb0[];
extern "C" u64 D_00359940[];
extern "C" u32 D_003591c8;

extern "C" void func_002f25a0(u32, u32);
extern "C" void func_002f3918(u32, u32);

void func_0020f188(void)
{
    u64* dest = D_00359940;
    dest[4] = D_01da8bb0[8];
    dest[5] = D_01da8bb0[9];
    func_002f25a0(0, 0);
    func_002f3918(D_003591c8, (u32)dest);
    asm volatile (""); // why: blocks tail call, keeps jal plus own return
}
