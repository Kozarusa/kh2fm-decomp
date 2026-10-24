#include "../common/types.h"
extern "C" u64 func_00305110(...);

u64 func_00304ec8(u8* object, u64 first, u64 second) {
    u64 result = func_00305110(*(u32*)(object + 0x54), *(s16*)(object + 0xe), first, second);
    if (result == (u64)-1) {
        *(u16*)(object + 0xc) = *(u16*)(object + 0xc) & 0xefff;
    } else {
        *(s32*)(object + 0x50) = (s32)result;
        *(u16*)(object + 0xc) = *(u16*)(object + 0xc) | 0x1000;
    }
    return result;
}
