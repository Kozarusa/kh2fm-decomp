#include "../common/types.h"
extern "C" u32 D_003638d0;
extern "C" u32 func_001c99b0(s64);
extern "C" u32 func_001d5b78(...);
extern "C" s32 func_00177860(s32);
// why: exact types of the accepted definition fm_primary_queuetau_recovered_001bbcc0.cpp; extern "C" because its C++ linkage fails the isolated probe link (v1)
extern "C" u32 func_001bbcc0(void);
extern "C" u64 func_00312db8(u64, u64);

s32 func_001d62b0(s32 owner, u8* state) {
    s32 result = 0;
    if (func_001c99b0(6) != 0) {
        return result;
    }
    u8* entry = (u8*)func_001d5b78(6, 1);
    s32 level = *(s32*)(state + 4);
    while (level < *(s32*)(entry + 4)) {
        entry += 8;
    }
    s32 chance = 100;
    if ((*(u32*)((u8*)func_00177860(owner) + 20) & 0x8000) == 0) {
        chance = entry[1] * func_001bbcc0();
    }
    D_003638d0 *= 0x10dcd;
    s32 roll = (s32)func_00312db8((u64)D_003638d0, 0x28f5c29);
    result = roll < chance;
    *(s32*)(state + 4) += 1;
    return result;
}
