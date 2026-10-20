#include "../common/types.h"
typedef s32 (*VirtualFn)(void*);

s32 func_001b9d40(u8* object) {
    s32 result = 0;
    VirtualFn method = *(VirtualFn*)(*(u8**)object + 0x40);
    if (method(object) != 0) {
        u32 flags = *(u32*)(object + 0x160);
        s32 flag = (flags & 4) != 0 ? 1 : (flags & 8) != 0 ? 1 : (flags & 0x10) != 0 ? 1 : 0;
        result = flag;
    }
    return result;
}