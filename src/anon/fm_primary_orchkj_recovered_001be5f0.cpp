#include "../common/types.h"
extern "C" bool func_0017a538(...);                // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" bool func_001917c0(void);               // copied from accepted caller fm_primary_addresspair_recovered_001a6c60.cpp
extern "C" u32 func_001bc778(...);                 // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);  // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
extern "C" bool func_001bd590(...);                // copied from accepted caller fm_primary_orchip_recovered_001ad158.cpp
extern "C" u32 func_001bdd20(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" bool func_001bdfe0(...);                // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u32 func_001be540(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
// why: types of the accepted definition fm_primary_orchcl_recovered_001be890.cpp, C linkage for the probe link
extern "C" void func_001be890(s32, s32);
extern "C" u32 func_001bf0c8(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp

// Return contract (DEVIATIONS #36): the func_001be890 tail exit is stale-b (accepted definition is void),
// the other exits leave the direct result of the final func_001bc780/func_001917c0 call, so void.

void func_001be5f0(u8* object) {
    s32 menu = (s32)(object + 36);
    if (func_001bd590((s32)object)) {
        func_001be890((s32)object, menu);
        return;
    }
    func_001bc778(menu);
    func_001be540(object, menu);
    if (*(s32*)(*(u8**)(object + 2528) + 2896) == 3) {
        func_001bf0c8(object);
        func_001bc780(menu, 707, 0, 1);
    } else {
        func_001bc780(menu, func_001bdfe0(object) ? 2 : 104, 0, 1);
    }
    if (func_001bdd20(object)) {
        func_001bc780(menu, 104, 0, 1);
    } else {
        func_001bc780(menu, 3, 0, 1);
    }
    u8 mark = 5; // why: one mark value set before the flag test; the original keeps 5 in s2 from the branch delay slot
    if (*(u32*)(object + 32) & 0x20) {
        func_001bc780(menu, 104, 0, 1);
        return;
    }
    if (func_0017a538(*(u8**)(object + 2528))) {
        u8* entry = (u8*)func_001bc780(menu, 5, 0, 1);
        // why: xor test, the original compares state 6 with xori+bnez instead of li+bne
        if ((*(s32*)(*(u8**)(object + 2528) + 2896) ^ 6) == 0 && func_001917c0()) {
            entry[5] = mark;
        }
    } else {
        u8* entry = (u8*)func_001bc780(menu, 4, 0, 1);
        if (*(s32*)(*(u8**)(object + 2528) + 2896) != 0) {
            entry[5] = mark;
        }
    }
}
