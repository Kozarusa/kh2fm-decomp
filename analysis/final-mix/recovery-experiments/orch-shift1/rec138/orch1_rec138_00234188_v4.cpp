#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234188(s32 first, s32 second, s32 third, s32 fourth, s32 fifth, s32 sixth) {
    s32 index = D_0035e360;
    // why: original retains the sequence number in t3.
    register s32 result asm("$11") = D_0035e368;
    s32* pointer = (s32*)(D_01dadc00 + index * 32);
    s32 next = (index + 1) & 63;
    s32 count = result + 1;
    pointer[7] = sixth;
    asm volatile("" ::: "memory"); // why: keeps store order
    D_0035e360 = next;
    D_0035e368 = count;
    pointer[0] = 3;
    pointer[2] = first;
    pointer[3] = second;
    pointer[4] = third;
    pointer[5] = fourth;
    pointer[6] = fifth;
    pointer[1] = result;
    return result;
}