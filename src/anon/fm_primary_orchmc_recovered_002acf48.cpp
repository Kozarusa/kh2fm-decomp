#include "../common/types.h"
extern "C" s32 D_0035f628;
extern "C" s32 D_0035f62c;
// why: type copied from the accepted definition in fm_primary_orchix_recovered_002ad110.cpp; extern "C" because the C++ form failed the isolated probe link (v1), whose linker script defines only the plain symbol
extern "C" u32 func_002ad110(void);
// why: no argument registers are set before these calls and their results are discarded
extern "C" s32 func_002ad258();
extern "C" s32 func_002ad390();
extern "C" s32 func_002ad580();
extern "C" s32 func_002ad6e8();
extern "C" s32 func_002ad878();
extern "C" s32 func_002ad9f8();
extern "C" s32 func_002adbd0();
extern "C" s32 func_002add90();
extern "C" s32 func_002ae320();
extern "C" s32 func_002adfd0();
// why: the original 002ae0c0 returns its own 0/1 flag (move v0,s1), so it is typed s32 like its sibling flags; the index goes in a0
extern "C" s32 func_002ae0c0(s32);

// why: the only exit leaves the last func_002ae0c0 result in v0, so it is returned (the flag is the callee's own 0/1 result)

s32 func_002acf48(void) {
    s32 index;
    s32 found;

    D_0035f62c = 0;
    D_0035f628 = 0;
    index = 0;
    func_002ad110();
    func_002ad258();
    func_002ad390();
    func_002ad580();
    func_002ad6e8();
    func_002ad878();
    func_002ad9f8();
    func_002adbd0();
    func_002add90();
    func_002ae320();
    func_002adfd0();
    D_0035f628 += 15;
    do {
        found = func_002ae0c0(index++);
        if (found) {
            D_0035f62c++;
        }
    } while (index < 15);
    return found;
}
