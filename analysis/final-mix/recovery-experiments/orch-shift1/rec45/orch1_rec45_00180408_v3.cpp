#include "../common/types.h"
extern "C" u32 func_00168b38(void*, u32, s32);

u32 func_00180408(u32 unused, u8* object) {
    if (object != 0) {
        u8* found = (u8*)func_00168b38(object, 9, 0);
        if (found != 0) {
            return *(u32*)(found + 8);
        }
    }
    return 0;
}
