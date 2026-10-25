#include "../common/types.h"
extern "C" s32 D_0035f2dc;
extern "C" s32 D_0035f2d8;
// why: copied from fm_primary_orchir_recovered_0026c9f0.cpp
extern "C" s32 func_00287df0(s32, s32, s32, s32, s32);
// why: copied from fm_primary_orchir_recovered_0026c9f0.cpp
extern "C" s32 func_00289310(s32);
// why: copied from fm_primary_orchir_recovered_0026c9f0.cpp
extern "C" s32 func_00289380(s32);
// why: types from the accepted definition fm_primary_orchem_recovered_0028ae28.cpp; extern "C" because
// its asm-label form failed the isolated link in v1 (the probe linker script defines only the plain symbol)
extern "C" s32 func_0028ae28(u8* object, s32 index);
// why: copied from fm_primary_orchfc_recovered_002b5078.cpp
extern "C" u32 func_0028ab20(u32);
// why: copied from fm_primary_dependencyfamily_recovered_00272a00.cpp
extern "C" u32 func_00138c10(s32, u32);

s32 func_00285760() {
    s32 cursor = func_00289380(D_0035f2dc);
    if (cursor != -1 || func_00289310(D_0035f2dc) != 0) {
        if (func_0028ae28((u8*)D_0035f2dc, 0) == 0) {
            func_00138c10(D_0035f2d8, 5);
            func_0028ab20(D_0035f2dc);
        }
    }
    func_00287df0(cursor, func_00289310(D_0035f2dc), 0, 0, 1);
    s32 result;
    switch (cursor) {
    case 0:
    case -2:
        result = 0;
        break;
    case 1:
        result = 1;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}
