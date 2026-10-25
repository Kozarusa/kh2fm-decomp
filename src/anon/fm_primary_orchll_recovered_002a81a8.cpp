#include "../common/types.h"
// Callee declarations copied from accepted fm_primary_orchip_recovered_00276888.cpp.
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00276a90(...);
extern "C" u32 func_00276b90(...);
extern "C" u8* D_0035f604;
// why: the virtual slot 5 results are discarded (same shape as the exact 002a67a8 loop).
typedef void (*Callback)(u8*);

s32 func_002a81a8(void) {
    s32 group = 0;
    do {
        s32 offset = group * 872;
        s32 count = 1;
        do {
            if (func_00139d78((u8*)(offset + (u32)D_0035f604)) != 0) {
                u8* object = (u8*)(offset + (u32)D_0035f604);
                (*(Callback**)object)[5](object);
            }
            count--;
            offset += 436;
        } while (count >= 0);
        group++;
    } while (group < 10);
    if (func_00276a90() == 0) {
        func_00276b90();
    }
    return 0;
}
