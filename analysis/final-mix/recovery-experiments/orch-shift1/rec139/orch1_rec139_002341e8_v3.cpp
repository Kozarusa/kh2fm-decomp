#include "../common/types.h"
extern "C" s32 D_0035e360;
extern "C" s32 D_0035e368;
extern "C" u8 D_01dadc00[];
s32 func_002341e8(s32 first, s32 second, s32 third) {
    s32 index = D_0035e360;
    register s32 serial asm("$11") = D_0035e368; // why: original serial uses t3
    s32* pointer = (s32*)(D_01dadc00 + index * 32);
    s32 nextIndex = (index + 1) & 63;
    register s32 nextSerial asm("$12") = serial + 1; // why: original next serial uses t4
    pointer[4] = third;
    D_0035e360 = nextIndex;
    D_0035e368 = nextSerial;
    pointer[0] = 4;
    pointer[2] = first;
    pointer[3] = second;
    pointer[1] = serial;
    return serial;
}
