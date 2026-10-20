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
    // why: original reloads the incoming pointer into t6 before materializing the offset
    register u32 input asm("$14") = payload[0];
    asm volatile("" : "+r"(input));
    // why: original materializes and updates the first destination in t7
    register u32 target asm("$15") = 0x8000;
    asm("" : "+r"(target));
    target = input + target;
    asm("" : "+r"(target));
    func_002b78ec(target);
    u32 storedInput = payload[0];
    // why: original materializes and updates the store destination in t7
    register u32 storeTarget asm("$15") = 0x48000;
    asm("" : "+r"(storeTarget));
    storeTarget = storedInput + storeTarget;
    asm("" : "+r"(storeTarget));
    *(u32*)storeTarget = 0;
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)));
}
