#include "../common/types.h"

extern "C" volatile u32 D_00361f60;
extern "C" void func_002ceb08(void);

// Preserve original registry aliases.
void func_002e2d88(u32 value, u32 flag) asm("_Z16u_tail4_002e2d88jjjj");

void func_002e2d88(u32 value, u32 flag)
{
    u8 *owner;
    flag = flag & 0xff;
    owner = (u8 *)D_00361f60;
    if (owner != 0)
    {
        func_002ceb08();
    }
    *(u32 *)(owner + 276) = value;
    *(u8 *)(owner + 280) = flag;
}
