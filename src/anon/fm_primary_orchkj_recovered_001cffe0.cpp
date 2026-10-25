#include "../common/types.h"
extern "C" u8 D_0036e368[];
extern "C" u32 func_001780d8(...);                          // copied from accepted caller fm_primary_clearsequence_recovered_001d7940.cpp
// why: accepted definition fm_primary_orchjm_recovered_00198860.cpp is s32 (u8*, s32)
extern "C" s32 func_00198860(u8* object, s32 command);
extern "C" void func_0017f488(u8*, s32, f32, f32);          // copied from accepted caller fm_primary_orchfj_recovered_002c17d8.cpp
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);      // copied from accepted caller fm_primary_orchfj_recovered_002c17d8.cpp
extern "C" u32 func_001987a8(...);                          // copied from accepted caller fm_resume_recovered_06.cpp

// why: void per DEVIATIONS #36; the only exit is the tail call to func_001987a8, which tail-calls func_00196f00, which tail-calls store-only func_00196e88 (no v0/$f0 write): stale-b. The result of func_001987a8 is therefore not returned.

void func_001cffe0(u8* object) {
    func_001780d8(object);
    func_00198860(object, 1);
    func_0017f488(object + 0x140, 191, 0.0f, 0.0f);
    func_0017f5e0(object + 0x140, 0, 0, 0.0f, 0.0f);
    func_001987a8(object, D_0036e368, object);
}
