#include "../common/types.h"

s32 func_002b8984(u32 object, s32 value, s32 index) {
    u8 argumentArea[16];
    asm volatile("" : "=m"(argumentArea)); // why: preserves original 16-byte argument area
    register void* frame asm("$30"); // why: original uses s8 as the frame pointer
    asm volatile("daddu %0,$29,$0" : "=r"(frame)); // why: original explicitly establishes s8 from sp
    volatile u32* payload = (volatile u32*)frame;
    payload[0] = object;
    payload[1] = (u32)value;
    payload[2] = (u32)index;
    *(volatile s32*)(payload[0] + 0x4801c) = (s32)payload[1];
    *(volatile s32*)(payload[0] + 0x48020) = (s32)payload[2];
    register s32 result asm("$15") = 0; // why: original transports zero through t7
    asm("" : "+r"(result)); // why: preserves the t7 result transport
    return result;
}
