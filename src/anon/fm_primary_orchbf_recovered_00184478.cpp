#include "../common/types.h"

typedef s32 (*Method)(void*);

s32 func_00184478(u8* object) {
    s32 result = 0;
    if ((*(Method*)(*(u8**)object + 0x40))(object)) {
        if (*(f32*)(object + 0x840) != *(f32*)(object + 0x540) ||
            *(f32*)(object + 0x848) != *(f32*)(object + 0x548)) {
            result = 1;
        }
    }
    return result;
}
