#include "../common/types.h"

u64 func_002b81b8(u32 value, u32 object, u32 index, u32 count) {
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea));
    register void* frame asm("$30");
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    u32* payload = (u32*)frame;
    payload[0] = value;
    payload[1] = object;
    payload[2] = index;
    payload[3] = count;
    asm volatile("" ::: "memory");
    register u64 result asm("$15") = 0;
    asm("" : "+r"(result));
    register u64 returned asm("$2") = result;
    asm("" : "+r"(returned));
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
