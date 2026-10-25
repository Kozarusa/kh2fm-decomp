#include "../common/types.h"
extern "C" u8 D_00351eb8[];
extern "C" u8 D_00351ec0[];
extern "C" s32 func_001a3570(u32);                 // copied from accepted caller fm_primary_orchjg_recovered_001a3958.cpp
extern "C" u16 func_001a36e0(...);                 // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" u32 func_001a3868(...);                 // copied from accepted caller fm_primary_oneword_recovered_001b72c0.cpp
extern "C" u16 func_001bbf40(...);                 // copied from accepted caller fm_oct7_extended_recovered_00.cpp
extern "C" u32 func_001bc778(...);                 // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" s32 func_001bc780(s32, u64, s32, u64);  // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" bool func_001c8db8(void*, s64);         // copied from accepted caller fm_primary_fiveword_recovered_001b2780.cpp
extern "C" u32 func_001c9b38(...);                 // copied from accepted caller fm_primary_oneword_recovered_001b72c0.cpp

void func_001beb00(u8* object) {
    if (*(u32*)(object + 32) & 0x20) {
        return;
    }
    u8* menu = object + 384;
    func_001bc778(menu);
    if (func_001c8db8(D_00351ec0, 1)) {
        return;
    }
    if (func_001c8db8(D_00351eb8, 0)) {
        return;
    }
    if (*(u32*)(*(u8**)(*(u8**)(object + 2528) + 12) + 8) & 0x20) {
        return;
    }
    if (func_001bbf40()) {
        return;
    }
    *(u32*)(object + 32) |= 0x20;
    for (s32 form = 1; form < 7; form++) {
        u16 item = func_001a36e0(form);
        if (func_001a3570(item) > 0) {
            u16* element = (u16*)func_001a3868(item);
            u32 kind = func_001c9b38(element);
            if (kind != 2) {
                u8* entry = (u8*)func_001bc780((s32)menu, *element, 0, 1);
                if (kind == 1) {
                    entry[5] = 5;
                }
            }
            *(u32*)(object + 32) &= ~0x20;
        }
    }
}
