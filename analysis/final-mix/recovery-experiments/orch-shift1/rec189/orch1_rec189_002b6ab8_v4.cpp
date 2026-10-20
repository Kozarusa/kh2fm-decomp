#include "../common/types.h"

s32 func_002b6ab8() {
    // why: original establishes s8 as the frame pointer
    register void* frame asm("$30");
    // why: original copies sp into s8
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    // why: original transports the zero result through t7
    register s32 result asm("$15") = 0;
    return result;
}
