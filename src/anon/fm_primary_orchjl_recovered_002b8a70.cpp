#include "../common/types.h"

extern "C" u32 func_002b78ec(u32);

u32 func_002b8a70(u8* base)
{
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea)); // why: original keeps a 32-byte frame with an argument area
    // why: original establishes an explicit frame pointer
    register void* frame asm("$30");
    // why: original transports the incoming pointer through the frame
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = (u32)base;
    // why: original reloads the incoming pointer into t6 before materializing the offset
    register u32 input asm("$14") = payload[0];
    asm volatile("" : "+r"(input)); // why: keeps the first reload in t6 ahead of the offset
    // why: original materializes and updates the first destination in t7
    register u32 target asm("$15") = 0x8000;
    asm("" : "+r"(target)); // why: keeps the 0x8000 offset materialized in t7
    target = input + target;
    asm("" : "+r"(target)); // why: keeps the first destination sum in t7 for the call argument
    u32 result = func_002b78ec(target);
    // why: original reloads the incoming pointer into t6 for the store
    register u32 storedInput asm("$14") = payload[0];
    asm volatile("" : "+r"(storedInput)); // why: scheduling barrier keeps the second t6 reload before the t7 high half
    // why: original materializes and updates the store destination in t7
    register u32 storeTarget asm("$15") = 0x48000;
    asm("" : "+r"(storeTarget)); // why: keeps the 0x48000 offset materialized in t7
    storeTarget = storedInput + storeTarget;
    asm("" : "+r"(storeTarget)); // why: keeps the store destination sum in t7
    *(u32*)storeTarget = 0;
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)));
    return result;
}
