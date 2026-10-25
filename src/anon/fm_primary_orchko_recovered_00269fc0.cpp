#include "../common/types.h"
struct EquipEntry {
    s16 field0;
    s16 field2;
    s16 field4;
};
extern "C" EquipEntry D_00373798[];
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00257770(...);
extern "C" u32 func_00287bc0();
// why: the definitions are Tz::CmTop::GetSelectPos (static s32(s32), tozawa/cmenu_top.cpp) and
// Tz::ItemInfo::GetEquipMax (u32(s32), tozawa/item_info.cpp); Tz member symbols failed the isolated
// link in orch1_lg404_002695a0_v1 because the probe linker script defines only the plain symbols.
extern "C" s32 func_002570a0(s32);
extern "C" u32 func_00269508(s32);

u32 func_00269fc0(void) {
    u32 result = 0;
    u32 buffer = func_00257770();
    u32 mode = func_00287bc0();
    if (buffer != 0 && func_00139d78(buffer) != 0) {
        s32 value = 228;
        if (mode != 2) {
            value = D_00373798[func_00269508(func_002570a0(2))].field4;
        }
        result = *(s32*)(buffer + 388) == value;
    }
    return result;
}
