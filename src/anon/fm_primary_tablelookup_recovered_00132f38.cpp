#include "../common/types.h"
extern "C" s32 func_00132c68(void);
extern "C" s32 func_001325c8(u32, s32, u32);

void func_00132f38(u32 object) {
    u8* base = (u8*)func_00132c68();
    s32 index = func_001325c8(object, 0, *(u32*)(base + 0x24));
    if (index >= 0) {
        u32 offset = *(u32*)(base + *(u32*)(base + 0x1c) + index * 4);
        *(u32*)(object + 0x274) = (u32)base + offset;
    }
}
