#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);
extern "C" s32 func_0019e210(u8***, s32);

s32 func_0019e170(u8*** object) {
    u8* owner = *(u8**)(**object + 0x9e0);
    s32 entry;
    if (*(u32*)(owner + 0x588) & 0x20000000) {
        s32* state = *(s32**)(owner + 0xb40);
        if (*state == 2) {
            return func_0019e210(object, state[1]);
        }
    }
    entry = 0;
    while ((entry = func_001b9bc8(entry)) != 0) {
        func_0019e210(object, entry);
    }
    return entry;
}
