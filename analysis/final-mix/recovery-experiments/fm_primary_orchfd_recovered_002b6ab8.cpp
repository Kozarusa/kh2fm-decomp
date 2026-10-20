#include "../common/types.h"

s32 func_002b6ab8() {
    // why: original establishes s8 as the frame pointer
    register void* frame asm("$30");
    // why: original copies sp into s8
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    // why: original transports the zero result through t7
    register s32 result asm("$15") = 0;
    asm("" : "+r"(result)); // why: preserve the t7 transport
    // why: original transports t7 into v0 before return
    register s32 returned asm("$2") = result;
    asm("" : "+r"(returned)); // why: preserve the v0 transport
    // why: original restores sp from s8 before the epilogue
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(returned));
    return returned;
}
