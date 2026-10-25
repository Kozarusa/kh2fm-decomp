#include "../common/types.h"
extern "C" u32 func_001bc778(s32);                      // copied from accepted caller fm_primary_fourwordfresh_recovered_002c14a8.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);       // copied from accepted caller fm_primary_fourwordfresh_recovered_002c14a8.cpp
// why: types copied from the accepted definition fm_primary_orchcq_recovered_001cf998.cpp, extern "C" added for the isolated probe link
extern "C" u32 func_001cf998(void);
// why: types copied from the accepted definition fm_primary_orchkb_recovered_001cf9e0.cpp, extern "C" added for the isolated probe link
extern "C" void func_001cf9e0(u8*, s32);
// why: types copied from the accepted definition fm_primary_orchjg_recovered_001d8898.cpp, extern "C" added for the isolated probe link
extern "C" s32 func_001d8898(s32);
extern "C" u32 func_00190128(void*);                    // copied from accepted caller fm_primary_fourwordfresh_recovered_002c14a8.cpp
extern "C" u32 func_00190878(void*, u32, u32);          // copied from accepted caller fm_primary_addresspair_recovered_001a6c60.cpp
// why: types copied from the accepted declaration in auto80_199_queue_decls.hpp (C++ linkage there), extern "C" added for the isolated probe link
extern "C" u32 func_001bd3e0(u32, u32, u32, void*, u32, u32);
extern "C" u32 func_00178888(s32);                      // copied from accepted caller fm_primary_fourwordfresh_recovered_002c14a8.cpp

// why: void per DEVIATIONS #36; the single exit follows func_00178888, whose skip path leaves the earlier 001d8898/001bd3e0 result that crossed this call (stale-a) and whose tail path reaches func_001d6ba0 (stale-a on its early exit, otherwise deeper callee results); no float result

void func_001cf7d8(u8* object) {
    u8 buffer[32];
    s32 menu = *(s32*)(object + 2884) + 1660;
    func_001bc778(menu);
    u8* entry = (u8*)func_001bc780(menu, 411, 0, 1);
    entry[6] = 1;
    if (func_001cf998() != 0) {
        func_001cf9e0(object, 0);
    } else {
        func_001cf9e0(object, 1);
        entry[5] = 5;
    }
    if (func_001d8898(1) != 0) {
        func_00190128(buffer);
        func_00190878(buffer, (u32)object, 0);
        func_001bd3e0(*(u32*)(object + 2884), 1, 412, buffer, 1, 100);
    }
    func_00178888((s32)object);
}
