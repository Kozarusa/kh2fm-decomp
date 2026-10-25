#include "../common/types.h"
struct EquipEntry {
    s16 field0;
    s16 field2;
    s16 field4;
};
extern "C" EquipEntry D_00373a30[];
extern "C" u32 func_00257770(void);
extern "C" s32 func_00139d78(u32);
extern "C" u32 func_00287bc0();
// why: the definition is Tz::CmTop::GetSelectPos (static s32(s32)); Tz member symbols failed the isolated
// link in orch1_lg404_002695a0_v1 because the probe linker script defines only the plain symbols.
extern "C" s32 func_002570a0(s32);
// why: a0 is the select position from v0 and v0 is scaled as a table index; no recovered declaration takes an argument
extern "C" u32 func_00272b60(s32);

u32 func_00272538(void) {
    u32 result = 0;
    u32 buffer = func_00257770();
    u32 mode = func_00287bc0();
    if (buffer != 0 && func_00139d78(buffer) != 0) {
        s32 value = 228;
        if (mode - 26 >= 2) {
            value = D_00373a30[func_00272b60(func_002570a0(26))].field4;
        }
        result = *(s32*)(buffer + 388) == value;
    }
    return result;
}
