#include "../common/types.h"
extern "C" u32 func_00257130(...);
extern "C" u32 func_002827e0(...);
// why: Tz::PartyInfo::GetAllHaveForm/GetAllDoubleWeaponForm (static u32 (void), tz/ui_accessors.cpp)
// fail the isolated link in v1: the probe linker script defines only the plain symbols.
extern "C" u32 func_002813b8(void);
extern "C" u32 func_00281420(void);

s32 func_002695a0(s32 value) {
    u32 counts[5];
    s32 i = 0;
    while (i < 5) {
        u32 v = func_00257130();
        v = func_002827e0(v, i);
        counts[i] = v;
        i = i + 1;
    }
    i = 0;
    s32 forms = func_002813b8() & func_00281420();
    value = value - (s32)counts[0];
    s32 count = 0;
    while (i < 7) {
        if ((u8)((forms >> i) & 1)) {
            if (value == count) {
                return i;
            }
            count = count + 1;
        }
        i = i + 1;
    }
    return i;
}
