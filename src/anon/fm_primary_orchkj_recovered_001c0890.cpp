#include "../common/types.h"
extern "C" u8 D_0032bb30[];                        // copied from accepted fm_primary_orchbl_recovered_00194930.cpp
extern "C" u8* D_01d49358;                         // copied from accepted fm_primary_orchcm_recovered_001c0648.cpp
// why: no accepted declaration; its exits leave a CheckFlag/HasAnsemEntry-derived v0 or tail into SetFlag
extern "C" s32 func_00181670(void);
extern "C" s32 func_001a1658(s32, s32);            // types of the accepted definition fm_primary_orchbr_recovered_001a1658.cpp
extern "C" u32 func_001a17c8(s32);                 // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" u8* func_001c0648(u32);                 // types of the accepted definition fm_primary_orchcm_recovered_001c0648.cpp
extern "C" s32 func_001c0690(u8*, u8*);            // types of the accepted definition fm_primary_orchjk_recovered_001c0690.cpp
extern "C" u32 func_001c09c0(u32);                 // types of the accepted definition auto200_999.cpp

// Return contract: accepted declarations say s32 YS::BONUSLEVEL::Up(s32) (yasui/libys/bonuslevel.hpp) and
// u32 func_001c0890(...); both exits leave a direct callee result (func_001c09c0, func_00181670 tail call).

// Preserve original registry aliases.
s32 func_001c0890(s32 level) asm("_ZN2YS10BONUSLEVEL2UpEi");

s32 func_001c0890(s32 level) {
    u8* entry = func_001c0648(level);
    s32 result = func_001c09c0(level);
    if (result != 0) {
        return result;
    }
    D_0032bb30[14080]++;
    *(u32*)(D_0032bb30 + 14084 + ((u32)level >> 5) * 4) |= 1 << (level & 0x1f);
    if (entry < D_01d49358 + *(s32*)(D_01d49358 + 4) * 16 + 8 && entry[0] == level) {
        do {
            s32 handle = func_001a1658(entry[1], -1);
            u8* current = entry;
            asm("" : "+r"(current)); // why: original copies the handle to s0 before it moves the entry into a0
            func_001c0690(current, (u8*)handle);
            entry += 16;
            func_001a17c8(handle);
        } while (entry < D_01d49358 + *(s32*)(D_01d49358 + 4) * 16 + 8 && entry[0] == level);
    }
    return func_00181670();
}
