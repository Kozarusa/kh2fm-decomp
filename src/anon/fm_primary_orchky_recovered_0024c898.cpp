#include "../common/types.h"
extern "C" u32 D_0035eda8;
extern "C" s8 D_0035edc5;
extern "C" u8* D_0035edbc;
extern "C" u16 func_002891e8(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00138c10(u8*, s32);
// why: signature of the accepted definition fm_primary_orchdz_recovered_00243230.cpp; extern "C" as at the call site in fm_primary_orchkx_recovered_00244e28.cpp, whose C++ declaration failed the isolated link (the probe linker script defines only the plain symbol)
extern "C" u8* func_00243230(u32 value, u32 index);

u32 func_0024c898(void) {
    u32 current = func_002891e8(D_0035eda8);
    if (!((D_0035edc5 >> current) & 1)) {
        return current;
    }
    s32 offset = current * 408;
    if (func_00139d78(D_0035edbc + offset) != 0) {
        u8* entry = D_0035edbc + offset;
        if (*(s32*)(entry + 388) != 37) {
            func_00138c10(entry, 37);
        }
    }
    return (u32)func_00243230(7, current);
}
