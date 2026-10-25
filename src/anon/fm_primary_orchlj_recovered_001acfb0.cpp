#include "../common/types.h"
// why: recovered call site fm_primary_orchjq_recovered_001aca98.cpp declares it this way; the result is
// unused here because func_001acfb0 is void (mixed-exit ruling 2026-10-20)
extern "C" u32 func_00239bf8(s32, s32);
// why: table of 3-byte entries indexed by the selection; byte 0 and byte 1 are the two codes
extern "C" u8 D_00350a38[];

void func_001acfb0(u8* object, s32 index) {
    if (index != *(s32*)(object + 476)) {
        *(s32*)(object + 476) = index;
        if (*(s32*)(object + 112) == 0) {
            func_00239bf8((s32)(object + 132), D_00350a38[index * 3]);
        } else {
            func_00239bf8((s32)(object + 132), D_00350a38[index * 3 + 1]);
            // why: a statement after the call keeps it a jal with the shared epilogue as in the original
            // (without it GCC turns this call into a second tail jump); the read itself is dead and emits nothing
            u8 code = D_00350a38[index * 3 + 1];
        }
    }
}
