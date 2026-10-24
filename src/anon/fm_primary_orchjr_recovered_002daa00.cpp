#include "../common/types.h"
extern "C" s32 func_0016c028(s32);
extern "C" u32 func_002bc188(u64,u64);

void func_002daa00(u8* object, s32 base) {
    s32 handle = *(s32*)(object + 0xbf4);
    if (handle != 0) {
        register s32 offset asm("$15") = 0x56ab8; // why: original builds the offset constant in t7
        s32 target = base + offset;
        func_002bc188(target, func_0016c028(handle));
    }
}
