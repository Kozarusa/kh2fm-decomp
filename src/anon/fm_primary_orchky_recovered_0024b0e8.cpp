#include "../common/types.h"
extern "C" u32 D_0035ed70;
extern "C" s8 D_0035ed9c;
extern "C" u32 D_0035ed8c;
extern "C" u32 func_002891e8(...);
extern "C" s32 func_00139d78(u32);
extern "C" void func_00138c10(u8*, s32);
// why: extern "C" plain symbol for the isolated probe link; the definition (fm_primary_orchdz_recovered_00243230.cpp) returns u8*
extern "C" u8* func_00243230(u32 value, u32 index);

// why: both exits are direct callee results (GetCurrent v0 on the skip path, func_00243230 v0 on the tail path), so the result is typed per R4.3

u32 func_0024b0e8() {
    u32 index = func_002891e8(D_0035ed70);
    if ((u8)(((D_0035ed9c >> index) ^ 1) & 1)) {
        return index;
    }
    s32 offset = index * 408;
    if (func_00139d78(D_0035ed8c + offset) != 0) {
        u8* entry = (u8*)(D_0035ed8c + offset);
        if (*(s32*)(entry + 388) != 37) {
            func_00138c10(entry, 37);
        }
    }
    return (u32)func_00243230(2, index);
}
