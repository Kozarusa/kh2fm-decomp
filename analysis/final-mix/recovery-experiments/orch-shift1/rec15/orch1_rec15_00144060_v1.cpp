#include "../common/types.h"

extern "C" u8* D_00348800;
extern "C" s32 D_00348810;
extern "C" u8 D_0034881f;
extern "C" u32 func_00106a60(...);
extern "C" void func_00107368(...);
extern "C" void func_00165f70(...);

void func_00144060() {
    u8 buffer[16];
    *(s32*)(D_00348800 + 0x770) = 0;
    if (D_00348810 != 0) {
        if (D_0034881f != 0) {
            u32 result = func_00106a60(1);
            func_00107368(result, buffer);
            func_00165f70(D_00348810, buffer, D_00348800 + 0x270, D_00348800 + 0x770, D_00348800 + 0x1f0);
        }
    }
}