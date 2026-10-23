#include "../common/types.h"
extern "C" s32 func_0016c028(...);
extern "C" u32 func_0018c480(s32,u8);
extern "C" u32 func_0018c490(...);

// Preserve original registry aliases.
s32 func_0018bbf8(s32 object) asm("_Z16ctarget_0018bbf8jjjj");

s32 func_0018bbf8(s32 object) {
    u8* member = (u8*)(object + 0xa40);
    s32 result;
    if (member[0x30] != 0) {
        return 0;
    }
    s32 value = func_0016c028();
    result = func_0018c490(member, value);
    if (result != 0) {
        func_0018c480((s32)member, 1);
    }
    return result;
}
