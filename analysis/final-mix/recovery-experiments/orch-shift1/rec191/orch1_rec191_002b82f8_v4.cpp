#include "../common/types.h"
extern "C" u8 D_01e22040[];
extern "C" s32 D_01e21f40;
extern "C" s32 func_003094b8(s32, s32, ...);

s32 func_002b82f8() {
    register void* frame asm("$30"); // why: original uses s8 as the frame pointer
    asm volatile("daddu %0,$29,$0" : "=r"(frame)); // why: original explicitly establishes s8 from sp
    volatile s32 result;
    do {
        result = func_003094b8((s32)D_01e22040, 2, 0, (s32)&D_01e21f40, 256, (s32)&D_01e21f40, 256, 0, 0);
    } while (result != 0);
    return D_01e21f40;
}
