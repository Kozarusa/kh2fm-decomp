#include "../common/types.h"

extern "C" u32 func_002b78ec(u32);

void func_002b8a70(u8* base)
{
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea));
    // why: original establishes an explicit frame pointer
    register void* frame asm("$30");
    // why: original transports the incoming pointer through the frame
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = (u32)base;
    // why: original forms the first destination in t7 before moving it to a0
    register u32 target asm("$15") = payload[0] + 0x8000;
    asm("" : "+r"(target));
    func_002b78ec(target);
    *(u32*)(payload[0] + 0x48000) = 0;
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)));
}
