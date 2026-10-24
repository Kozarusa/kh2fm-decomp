#include "../common/types.h"
extern "C" s64 func_00305168(void*,u64,u64,u64);

s32 func_00304de8(u8* object, u64 first, u64 second) {
    s32 result = func_00305168(*(void**)(object + 0x54), *(s16*)(object + 0xe), first, second);
    if (result >= 0) {
        *(s32*)(object + 0x50) = *(s32*)(object + 0x50) + result;
    } else {
        *(u16*)(object + 0xc) = *(u16*)(object + 0xc) & 0xefff;
    }
    return result;
}
