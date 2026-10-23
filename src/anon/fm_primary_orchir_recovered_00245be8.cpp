#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f070(...);
extern "C" u32 func_0023f0c0(...);
extern "C" u32 func_002468a0(...);
extern "C" u32 func_002469a0(...);
extern "C" u32 func_002891e8(...);
extern "C" void func_0028ab20(...);
extern "C" u32 func_0028acc8(...);
extern "C" s32 D_0035ed20;
extern "C" s32 D_0035ed28;
extern "C" s32 D_0035ed2c;
extern "C" s32 D_0035ed30;

s32 func_00245be8(void) {
    s32 count;
    s32 entry;
    register s32 result;
    u32 select;
    result = func_00139d78(D_0035ed28);
    if (result && (result = func_0023f0c0(D_0035ed28), 0x20 != result)) {
        func_0023f070(D_0035ed28, 0x20, 0xffffffffffffffff);
    }
    result = func_0028acc8(D_0035ed20);
    if (result != 0) {
        func_0028ab20(D_0035ed20);
        select = func_002891e8(D_0035ed20);
        select = func_002469a0(select);
        entry = func_002468a0(select);
        result = func_00139d78(D_0035ed30);
        if (result) {
            count = func_0023f0c0(D_0035ed30);
            if (count != *(s16*)(entry + 4)) {
                func_0023f070(D_0035ed30, *(s16*)(entry + 4), 0xffffffffffffffff);
            }
        }
    }
    result = func_00139d78(D_0035ed2c);
    if (result && (result = func_0023f0c0(D_0035ed2c), result != 0x23)) {
        return func_0023f070(D_0035ed2c, 0x23, 0xffffffffffffffff);
    }
    return result;
}
