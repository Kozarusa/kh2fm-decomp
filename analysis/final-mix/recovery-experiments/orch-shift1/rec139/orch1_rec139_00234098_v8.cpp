#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_00234098(s32 first, s32 second, s32 third) {
    register s32 index asm("$14") = D_0035e360; // why: original index load uses t6
    register s32 serial asm("$11") = D_0035e368; // why: original serial uses t3
    asm("" : "+r"(serial)); // why: preserves serial allocation
    s32* pointer = (s32*)(D_01dadc00 + index * 32);
    s32 nextIndex = (index + 1) & 63;
    asm("" : "+r"(pointer)); // why: original pointer computation precedes serial increment
    register s32 nextSerial asm("$12") = serial + 1; // why: original incremented serial uses t4
    asm("" : "+r"(nextSerial)); // why: retains original t4 incremented serial
    pointer[4] = third;
    D_0035e360 = nextIndex;
    D_0035e368 = nextSerial;
    pointer[0] = 1;
    pointer[2] = first;
    pointer[3] = second;
    pointer[1] = serial;
    return serial;
}
