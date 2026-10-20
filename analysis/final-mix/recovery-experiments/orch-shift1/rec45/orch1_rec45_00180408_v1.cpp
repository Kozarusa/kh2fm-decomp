#include "../common/types.h"
extern "C" u32 func_00168b38(void*, u32, s32);

u32 func_00180408(u32 unused, u8* object) {
    u32 result;
    if (object == 0) {
        result = 0;
    } else {
        u8* found = (u8*)func_00168b38(object, 9, 0);
        if (found == 0) {
            result = 0;
        } else {
            result = *(u32*)(found + 8);
        }
    }
    return result;
}
