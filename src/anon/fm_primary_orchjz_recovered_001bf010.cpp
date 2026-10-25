#include "../common/types.h"
extern "C" s32 func_0016b800(...);                     // copied from accepted caller fm_primary_width_recovered_00.cpp
extern "C" bool func_0019ba60(u64);                    // copied from accepted caller fm_primary_orchbh_recovered_00187420.cpp
extern "C" u32 func_00190878(void*,u32,u32);           // copied from accepted caller fm_primary_orchbk_recovered_00190a28.cpp
extern "C" u32 func_001bc778(...);                     // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);      // copied from accepted caller fm_primary_orchcl_recovered_001be890.cpp
// why: the accepted varargs u64 placeholder (fm_scalar_extra_recovered_12.cpp) adds a dsll32/dsra32 truncation in v1; types from the accepted definition u32 func_001c8bb8(u8*) in auto80_199_queue.cpp, plus extern "C"
extern "C" u32 func_001c8bb8(u8*);
extern "C" u64 func_001c8cc0(...);                     // copied from accepted fm_scalar_extra_recovered_12.cpp

u8* func_001bf010(u8* object) {
    s8 list[16];
    s32 index = 0;
    s32 target = func_0016b800(201);
    func_0019ba60(target);
    u8* slot = object + 0xa90;
    u8* menu = object + 0x180;
    func_00190878(slot, target, 0);
    func_001bc778(menu);
    s32 count = func_001c8bb8((u8*)list);
    for (; index < count; index++) {
        func_001bc780((s32)menu, func_001c8cc0(list[index]), (s32)slot, 1);
    }
    return menu;
}
