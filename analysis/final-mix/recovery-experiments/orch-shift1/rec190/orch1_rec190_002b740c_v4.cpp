#include "../common/types.h"

u64 __attribute__((aligned(4))) func_002b740c(u32 first, u32 second, u32 third, u32 fourth)
{
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea));
    // why: original transports arguments through the explicit frame pointer
    register void* frame asm("$30");
    // why: original establishes the frame pointer after saving it
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = first;
    payload[1] = second;
    payload[2] = third;
    payload[3] = fourth;
    // why: original materializes zero in t7 before moving it to v0
    register u64 result asm("$15") = 0;
    asm("" : "+r"(result));
    // why: original returns the t7 value through v0
    register u64 returned asm("$2") = result;
    asm("" : "+r"(returned));
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
