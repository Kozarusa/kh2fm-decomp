#include "../common/types.h"

u32 func_002b8694(s32 value)
{
    u8 argumentArea[32];
    asm volatile("" : "=m"(argumentArea)); // why: original keeps a 48-byte frame for its locals
    // why: original addresses its locals through the explicit frame pointer
    register void* frame asm("$30");
    // why: original establishes the frame pointer after saving it
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile s32* payload = (volatile s32*)frame;
    payload[0] = value;
    // why: original computes every byte in t7
    register s32 low asm("$15") = payload[0] & 0xff;
    asm("" : "+r"(low)); // why: pins the byte to t7
    payload[4] = low;
    // why: original computes every byte in t7
    register s32 second asm("$15") = (payload[0] >> 8) & 0xff;
    asm("" : "+r"(second)); // why: pins the byte to t7
    payload[5] = second;
    // why: original computes every byte in t7
    register s32 third asm("$15") = (payload[0] >> 16) & 0xff;
    asm("" : "+r"(third)); // why: pins the byte to t7
    payload[6] = third;
    // why: original computes every byte in t7
    register s32 high asm("$15") = payload[0] >> 24;
    asm("" : "+r"(high)); // why: original keeps the sra plus mask instead of folding them into srl
    payload[7] = high & 0xff;
    // why: original accumulates the swapped value in t7
    register u32 result asm("$15") = payload[4] << 24;
    asm volatile("" : "+r"(result) : : "memory"); // why: keeps the shift before the next frame load
    // why: original loads each shifted byte into t6
    register u32 part asm("$14") = payload[5] << 16;
    asm("" : "+r"(part)); // why: pins the shifted byte to t6
    result = result | part;
    asm volatile("" : "+r"(result) : : "memory"); // why: keeps the or before the next frame load
    // why: original loads each shifted byte into t6
    register u32 part2 asm("$14") = payload[6] << 8;
    asm("" : "+r"(part2)); // why: pins the shifted byte to t6
    result = result | part2;
    asm volatile("" : "+r"(result) : : "memory"); // why: keeps the or before the next frame load
    // why: original loads each shifted byte into t6
    register u32 part3 asm("$14") = payload[7];
    asm("" : "+r"(part3)); // why: pins the byte to t6
    result = result | part3;
    asm("" : "+r"(result)); // why: keeps the value in t7 instead of building it in v0
    // why: original returns the t7 value through v0
    register u32 returned asm("$2") = result;
    asm("" : "+r"(returned)); // why: keeps the separate move from t7 to v0
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
