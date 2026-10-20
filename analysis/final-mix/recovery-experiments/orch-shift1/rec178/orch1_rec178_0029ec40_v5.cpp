#include "../common/types.h"
extern "C" u16 D_00374aa0[];
s32 func_0029ec40(u32 value) {
    register s32 result asm("$2")=0; // why: preserve original default result register
    u32 index=0;
    if(D_00374aa0[0]) {
        do {
            if(D_00374aa0[index]==value) { result=1; return result; }
            ++index;
        } while(D_00374aa0[index]);
    }
    return result;
}



