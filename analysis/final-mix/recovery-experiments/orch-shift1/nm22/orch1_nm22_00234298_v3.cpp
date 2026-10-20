#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234298(s32 first, s32 second, s32 third, s32 fourth) {
    s32 index = D_0035e360;
    s32 serial = D_0035e368;
    s32* pointer = (s32*)(D_01dadc00 + index * 32);
    register s32 nextIndex asm("$13") = (index + 1) & 63; // why: original next index uses t5
    asm("" : "+r"(nextIndex)); // why: original next index computation precedes serial increment
    asm("" : "+r"(serial) : "r"(nextIndex)); // why: original masked index precedes serial increment
    register s32 nextSerial asm("$12") = serial + 1; // why: original next serial uses t4
    asm("" : "+r"(nextSerial)); // why: retains original next serial allocation
    pointer[5] = fourth;
    asm volatile("" ::: "memory"); // why: keeps store order
    register s32 tag asm("$15") = 6; // why: original tag uses t7 before global stores
    asm volatile("" : "+r"(tag) : : "memory"); // why: keeps tag materialization before global stores
    register s32 result asm("$2") = serial; // why: original return serial uses v0 before global stores
    asm volatile("" : "+r"(result) : : "memory"); // why: materializes returned serial before global stores
    D_0035e360 = nextIndex;
    D_0035e368 = nextSerial;
    pointer[0] = tag;
    pointer[2] = first;
    pointer[3] = second;
    pointer[4] = third;
    pointer[1] = serial;
    return result;
}
