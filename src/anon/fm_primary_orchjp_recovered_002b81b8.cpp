#include "../common/types.h"

u64 func_002b81b8(u32 value, u32 object, u32 index, u32 count) {
    u8 argumentArea[16];
    // why: original keeps a 32-byte frame while storing the incoming arguments
    asm volatile("" : "=m"(argumentArea));
    // why: original transports arguments through the explicit frame pointer
    register void* frame asm("$30");
    // why: original establishes the frame pointer after saving it
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = value;
    payload[1] = object;
    payload[2] = index;
    payload[3] = count;
    // why: keeps the zero result after the final argument store
    asm volatile("" ::: "memory");
    // why: original materializes zero in t7 before moving it to v0
    register u64 result asm("$15") = 0;
    asm("" : "+r"(result) : "m"(payload[0]));
    // why: original returns the t7 value through v0
    register u64 returned asm("$2") = result;
    asm("" : "+r"(returned));
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
