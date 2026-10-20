#include "../common/types.h"

s32 func_002b81b8(s32 value, s32 object, s32 index, s32 count) {
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea)); // why: preserves original 16-byte argument area
    register void* frame asm("$30"); // why: original uses s8 as the frame pointer
    asm volatile("daddu %0,$29,$0" : "=r"(frame)); // why: original explicitly establishes s8 from sp
    volatile s32* payload = (volatile s32*)frame;
    payload[0] = value;
    payload[1] = object;
    payload[2] = index;
    payload[3] = count;
    register s32 result asm("$15") = 0; // why: original transports zero through t7
    asm("" : "+r"(result)); // why: preserves the t7 result transport
    return result;
}
