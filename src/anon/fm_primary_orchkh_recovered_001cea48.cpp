#include "../common/types.h"
// why: types copied from the accepted call-site declaration in auto80_199_queue_decls.hpp; extern "C" added because the C++-linkage form failed the isolated probe link
extern "C" void func_002877a0(u32, u32, u32);

// why: void per DEVIATIONS #36; the two early exits leave the untouched entry v0, the call paths end in void func_002877a0 (tail into void func_001386e0 or Sprite::setNum, no v0/$f0 result): entry and stale-b

void func_001cea48(s32* object, s32* owner, u64* flags) {
    u64 bits = *flags;
    s32 state;
    // why: bool conversion of the flag bit gives the original's extra andi 0xff (a plain test drops it)
    if ((bits & (1ULL << 34)) != 0 && (bool)(object[1] & 1)) {
        func_002877a0((u32)(object + 3), 0, 3);
        if ((object[1] & 2) != 0) {
            func_002877a0((u32)(object + 3), 1, 4);
        }
        state = 1;
    } else {
        if ((bits & (1ULL << 35)) == 0) {
            return;
        }
        if ((object[1] & 2) == 0) {
            return;
        }
        func_002877a0((u32)(object + 3), 1, 3);
        // why: bool conversion of the flag bit gives the original's extra andi 0xff
        if ((bool)(object[1] & 1)) {
            func_002877a0((u32)(object + 3), 0, 4);
        }
        state = 2;
    }
    owner[732] = state;
    register s32 done asm("$14") = 3; // why: original materializes the final state constant in t6
    object[0] = done;
}
