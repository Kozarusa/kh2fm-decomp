#include "../common/types.h"
extern "C" u32 func_00139510(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00257770(...);
extern "C" void func_0027e770(...);
extern "C" u32 func_0027e920(...);
extern "C" u32 func_0028abe0(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" s32 D_0035f020;
extern "C" s32 D_0035f024;

// Preserve original registry aliases.
u32 func_00262ff8(void) asm("_ZN2Tz6CmItem9LeaveHelpEv");

u32 func_00262ff8(void) {
    u32 result;
    s32 base = func_00257770();
    if (func_00139d78(base + 0x198) != 0) {
        func_00139510(base + 0x198);
    }
    if (func_00139d78(base + 0x814) != 0) {
        func_00139510(base + 0x814);
    }
    if (func_0028acc8(D_0035f020) != 0) {
        func_0028abe0(D_0035f020);
    }
    if (func_0028acc8(D_0035f024) != 0) {
        func_0028abe0(D_0035f024);
    }
    if (func_0027e920() != 0) {
        func_0027e770();
    }
    result = func_00139d78(base + 0x4c8);
    if (result != 0) {
        return func_00139510(base + 0x4c8);
    }
    return result;
}
