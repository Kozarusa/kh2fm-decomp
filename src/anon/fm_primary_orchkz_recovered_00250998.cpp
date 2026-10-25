#include "../common/types.h"
extern "C" u32 D_0035ee34;
extern "C" s8 D_0035ee51;
extern "C" u8* D_0035ee48;
extern "C" u16 func_002891e8(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00138c10(u8*, s32);
// why: signature of the accepted definition fm_primary_orchdz_recovered_00243230.cpp; extern "C" because the isolated probe linker script defines only the plain symbol (same form as fm_primary_orchkx_recovered_00244e28.cpp)
extern "C" u8* func_00243230(u32 value, u32 index);

// why: both exits return a direct callee result (func_002891e8 on the early exit, func_00243230 on the tail call), as in sibling 00244e28

u32 func_00250998(void) {
    u32 current = func_002891e8(D_0035ee34);
    if (!((D_0035ee51 >> current) & 1)) {
        return current;
    }
    s32 offset = current * 408;
    if (func_00139d78(D_0035ee48 + offset) != 0) {
        u8* entry = D_0035ee48 + offset;
        if (*(s32*)(entry + 388) != 34) {
            func_00138c10(entry, 34);
        }
    }
    return (u32)func_00243230(6, current);
}
