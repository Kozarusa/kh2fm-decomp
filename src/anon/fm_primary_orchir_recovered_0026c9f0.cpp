#include "../common/types.h"
extern "C" s32 func_00242848(s32);
extern "C" s32 func_00257610(s32);
extern "C" s32 func_0026c048();
extern "C" s32 func_0026c470();
extern "C" s32 func_0026d168();
extern "C" s32 func_0026d180();
extern "C" s32 func_00287c00(s32);
extern "C" s32 func_00287c30();
extern "C" s32 func_00287c90(s32);
extern "C" s32 func_00287cd0();
extern "C" s32 func_00287df0(s32, s32, s32, s32, s32);
extern "C" s32 func_00289310(s32);
extern "C" s32 func_00289380(s32);
extern "C" s32 func_0028af18(s32, s32);
extern "C" s32 D_0035f024;

s32 func_0026c9f0() {
    s32 state;
    s32 cursor;
    s32 result;
    s32 value;
    cursor = func_00289380(D_0035f024);
    state = func_00287cd0();
    result = func_0026c470();
    if (state == 2) {
        result = func_0026d180();
        if (result == 0) {
            func_00287c30();
            func_0026c048();
            return func_0028af18(D_0035f024, 0x73);
        }
        return result;
    }
    if (state == 0) {
        result = func_00257610(1);
        if (result != 0) {
            result = func_00287c90(1);
        }
    }
    if (state == 1) {
        value = func_00289310(D_0035f024);
        value = func_00287df0(cursor, value, 0, 0, 1);
        result = func_00242848(value);
        if (result == 0 && (cursor == -2 || (cursor > -2 && (u64)cursor != (u64)-1 && cursor == 0))) {
            func_0026d168();
            func_00287c00(0x14);
            return func_00287c90(1);
        }
    }
    return result;
}
