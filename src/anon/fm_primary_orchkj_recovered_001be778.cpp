#include "../common/types.h"
extern "C" u32 func_001819c0(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u32 func_00181a18(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u32 func_001bc778(...);                 // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);  // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
extern "C" bool func_001bd590(...);                // copied from accepted caller fm_primary_orchip_recovered_001ad158.cpp
extern "C" u32 func_001be540(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
// why: types of the accepted definition fm_primary_orchcl_recovered_001be890.cpp, C linkage for the probe link
extern "C" void func_001be890(s32, s32);
extern "C" int func_001bf010(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u32 func_001c8ab0(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u64 func_001c8ad8(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp

// Return contract (DEVIATIONS #36): the func_001be890 tail exit is stale-b (accepted definition is void),
// the other exit is the direct result of the final func_001bc780 tail call, so void.

void func_001be778(u8* object) {
    s32 menu = (s32)(object + 732);
    if (func_001bd590((s32)object)) {
        func_001be890((s32)object, menu);
        return;
    }
    func_001bc778(menu);
    func_001be540(object, menu);
    if (!func_001c8ab0()) {
        if (*(s32*)(object + 856) > 0) {
            func_001bc780(menu, 72, 0, 1);
        } else {
            func_001bc780(menu, 104, 0, 1);
        }
    } else {
        func_001bc780(menu, 316, 0, 1);
    }
    if (func_001c8ab0() == 2 && func_001c8ad8() == 201) {
        func_001bf010(object);
        func_001bc780(menu, 605, 0, 1);
    } else {
        func_001bc780(menu, func_001819c0() ? 73 : 104, 0, 1);
    }
    func_001bc780(menu, func_00181a18() ? 81 : 104, 0, 1);
}
