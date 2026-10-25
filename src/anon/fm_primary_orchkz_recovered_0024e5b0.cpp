#include "../common/types.h"
extern "C" u32 D_0035edcc;
extern "C" s8 D_0035edfc;
extern "C" u8* D_0035ede8;
extern "C" s32 D_0035edf4;
extern "C" u16 func_002891e8(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00138c10(u8*, s32);
// why: signature of the accepted definition fm_primary_orchdz_recovered_00243230.cpp; extern "C" copied from the accepted caller fm_primary_orchkx_recovered_00244e28.cpp (the probe linker script defines only the plain symbol)
extern "C" u8* func_00243230(u32 value, u32 index);

u32 func_0024e5b0(void) {
    u32 current = func_002891e8(D_0035edcc);
    if (((D_0035edfc >> current) ^ 1) & 1) {
        return current;
    }
    if (func_00139d78(D_0035ede8 + current * 408) != 0) {
        u8* entry = D_0035ede8 + current * 408;
        if (*(s32*)(entry + 388) != 37) {
            func_00138c10(entry, 37);
        }
    }
    if (D_0035edf4 != 0) {
        current += 3;
    }
    return (u32)func_00243230(0, current);
}
