#include "../common/types.h"

extern "C" u8 D_01e22040[];
extern "C" s32 D_01e21f40;
extern "C" s32 func_003094b8(u8*, s32, s32, s32*, s32, s32*, s32, s32, s32);

s32 func_002b84b8()
{
    // why: original establishes an explicit frame pointer
    register void* frame asm("$30");
    // why: original transports locals through the explicit frame pointer
    asm volatile("daddu %0,$29,$0" : "=r"(frame));
    volatile s32 result;
    do {
        result = func_003094b8(D_01e22040, 4, 0, &D_01e21f40, 0x100,
                               &D_01e21f40, 0x100, 0, 0);
    } while (result != 0);
    // why: original loads the global result through t7
    register s32 returned asm("$15") = D_01e21f40;
    asm("" : "+r"(returned));
    // why: original returns t7 through v0
    register s32 output asm("$2") = returned;
    asm("" : "+r"(output));
    // why: original restores sp from the explicit frame pointer
    asm("daddu $29,%0,$0" : : "r"(__builtin_frame_address(0)), "r"(output));
    return output;
}
