#include "../common/types.h"

u64 func_002b81ec(u32 input) asm("_Z13func_002b81ecPv");

u64 func_002b81ec(u32 input) {
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea));
    register void* frame asm("$30");
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    u32* payload = (u32*)frame;
    payload[0] = input;
    register u64 result asm("$15") = 0;
    asm("" : "+r"(result));
    register u64 returned asm("$2") = result;
    asm("" : "+r"(returned));
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
