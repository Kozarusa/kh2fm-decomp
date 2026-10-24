#include "../common/types.h"
typedef s32 (*VirtualFn)(void*);

s32 func_001b9d40(u8* object) {
    s32 result = 0;
    VirtualFn method = *(VirtualFn*)(*(u8**)object + 0x40);
    if (method(object) != 0) {
        s32 value = 0;
        u32 flags = *(u32*)(object + 0x160);
        if ((flags & 4) != 0) goto set;
        if ((flags & 8) != 0) goto set;
        if ((flags & 0x10) == 0) goto done;
    set:
        value = 1;
    done:
        result = value;
    }
    return result;
}
