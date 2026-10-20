#include "../common/types.h"
extern "C" u32 func_001de4b0(s32,u64,s32);
s32 func_0022e0a8(u8* object) {
    s32 result = 0;
    s32 output;
call:
    result = func_001de4b0((s32)(object + 16), 0, result);
    output = 1;
    if (result != 0) goto repeat;
    output = 0;
finish:
    return output;
repeat:
    if (*(s32*)(object + 12) == result) goto finish;
    asm("" : "+r"(result)); // why: original repeats through a distinct block transporting callee result to a2
    goto call;
}
