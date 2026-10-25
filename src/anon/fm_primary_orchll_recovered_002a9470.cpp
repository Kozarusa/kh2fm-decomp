#include "../common/types.h"
// why: single pointer argument in a0, as at the accepted call site in fm_primary_orcheh_recovered_00276b10.cpp, written without varargs
extern "C" u32 func_00139d78(u8*);
// Signatures of the accepted definitions fm_primary_orcheh_recovered_00276a90.cpp and fm_primary_orchld_recovered_00276b90.cpp.
// why: extern "C" because the C++ declaration fails the isolated link (lg444 002a9048 v1): the probe linker script defines only the plain symbol
extern "C" s32 func_00276a90();
// why: extern "C" for the same isolated-link reason as func_00276a90
extern "C" s32 func_00276b90();
extern "C" u8* D_0035f60c;
typedef void (*Callback)(u8*);

// why: the only exit loads the own constant 0 into v0, so a typed return of 0 is written

s32 func_002a9470() {
    s32 offset = 0;
    s32 count = 9;
    do {
        if (func_00139d78(D_0035f60c + offset)) {
            u8* object = (u8*)(offset + (u32)D_0035f60c);
            Callback* table = *(Callback**)object;
            table[5](object);
        }
        count--;
        offset += 436;
    } while (count >= 0);
    if (func_00276a90() == 0) {
        func_00276b90();
    }
    return 0;
}
