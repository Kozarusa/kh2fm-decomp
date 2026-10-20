#include "../common/types.h"
extern "C" volatile s32 D_01e2a3c0;

s32 func_002b99a0(u32 value, u32 object, u32 index, u32 count) {
    register void* frame asm("$30"); // why: original uses s8 as the frame pointer
    asm volatile("daddu %0,$29,$0" : "=r"(frame)); // why: original explicitly establishes s8 from sp
    register s32 result asm("$15") = D_01e2a3c0; // why: original loads the result through t7
    register s32 returned asm("$2") = result; // why: original copies t7 into v0 before restoring the frame
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned)); // why: original explicitly restores sp from s8
    return returned;
}
