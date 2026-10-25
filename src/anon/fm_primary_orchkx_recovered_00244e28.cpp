#include "../common/types.h"
extern "C" u32 D_0035ece8;
extern "C" s8 D_0035ed14;
extern "C" u8* D_0035ed04;
extern "C" u16 func_002891e8(...);
// why: no recovered source calls this function; one word argument (a0) and its v0 result is used as a shift count
extern "C" u32 func_00244ee8(u32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00138c10(u8*, s32);
// why: signature of the accepted definition fm_primary_orchdz_recovered_00243230.cpp; extern "C" because the C++ declaration failed the isolated link in v1 (the probe linker script defines only the plain symbol)
extern "C" u8* func_00243230(u32 value, u32 index);

u32 func_00244e28(void) {
    u32 current = func_002891e8(D_0035ece8);
    u32 index = func_00244ee8(current);
    if (!((D_0035ed14 >> index) & 1)) {
        return index;
    }
    s32 offset = current * 408;
    if (func_00139d78(D_0035ed04 + offset) != 0) {
        u8* entry = D_0035ed04 + offset;
        if (*(s32*)(entry + 388) != 37) {
            func_00138c10(entry, 37);
        }
    }
    return (u32)func_00243230(3, index);
}
