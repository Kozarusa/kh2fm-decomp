#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u8 D_0033bc10[];
extern "C" u32 func_00105868(s32);
extern "C" s32 func_001a35f8(...);
extern "C" bool func_001e0a90(...);
extern "C" u32 func_00276fd0(void);

// Preserve original registry aliases.
bool func_001d98a0(void) asm("_ZN2YS13BATTLE_REPORT15IsFMSecretMovieEv");

bool func_001d98a0(void) {
    // why: signed switch gives the original slti range test in the case tree (v1/v2 unsigned switch tested linearly)
    switch ((s32)func_00105868((s32)D_0032bb30)) {
    case 0:
        return false;
    case 1:
        // why: xori+bnez in the original; == 100 here emitted li+bne (v5)
        return (func_00276fd0() ^ 100) == 0 && func_001e0a90(D_0033bc10) != 0;
    case 2:
        return func_00276fd0() == 100;
    case 3:
        return func_001a35f8(593, 100) > 0 && func_001a35f8(594, 100) > 0 && func_001a35f8(595, 100) > 0;
    }
    return false;
}
