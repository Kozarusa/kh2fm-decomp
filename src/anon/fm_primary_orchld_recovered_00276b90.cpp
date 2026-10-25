#include "../common/types.h"
// why: result type from the testing call site in fm_primary_orcheh_recovered_00276a90.cpp; the one pointer argument is read from a0 here
extern "C" u32 func_00139d78(u8*);
extern "C" u8* D_0035f21c;

s32 func_00276b90() {
    register s32 offset asm("$16") = 0; // why: original offset counter lives in s0
    s32 index = 0;
    s32 result = 0;
    do {
        u8* object = D_0035f21c + offset;
        u32 flag = func_00139d78(object + 0xa998);
        offset += 408;
        asm volatile("" : "+r"(index)); // why: keeps original index increment after call
        if (flag) { result = 1; break; }
        index++;
    } while (index < 32);
    return result;
}
