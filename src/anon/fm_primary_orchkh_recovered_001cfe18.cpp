#include "../common/types.h"
extern "C" u8 D_00352360[];
extern "C" u8 D_00351eb8[];
extern "C" u8 D_00351ec0[];
extern "C" u8 D_0034e8b8[];
extern "C" u8 D_0034ee08[];
extern "C" u32 func_001c8d98(void*,u32);   // copied from accepted caller fm_primary_oneword_recovered_001c8710.cpp
// why: types copied from the accepted definition fm_primary_orchco_recovered_001c9b90.cpp, extern "C" added for the isolated probe link
extern "C" void func_001c9b90();
extern "C" u64 func_001d2710(...);         // copied from accepted caller fm_primary_fiveword_recovered_001e0958.cpp
extern "C" void func_00319f88(u32);        // copied from accepted caller fm_primary_orchgk_recovered_002d0fb0.cpp
extern "C" void func_0019f9a8(u32);        // copied from accepted caller fm_primary_orchfl_recovered_002d0028.cpp
extern "C" void func_001c0248(u32);        // copied from accepted caller fm_primary_orchfl_recovered_002d0028.cpp
extern "C" void func_00319fb0(u32);        // copied from accepted caller fm_primary_orchfl_recovered_002d0028.cpp (void, as its accepted definition in auto200_999.cpp)

// why: void per DEVIATIONS #36; the only exit follows the final call to func_00319fb0, whose accepted definition is void (its chain 0016a358 -> 001ddd88 ends in void callees): stale-b

void func_001cfe18(u32 object) {
    *(u32*)object = (u32)D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(object + 2932);
    *(u32*)object = (u32)D_0034e8b8;
    func_00319f88(object + 2824);
    *(u32*)object = (u32)D_0034ee08;
    func_0019f9a8(object + 2568);
    func_001c0248(object + 2640);
    func_00319fb0(object);
    asm volatile("" ::: "memory"); // why: preserves the original non-tail final call (pattern of accepted func_002d0fb0)
}
