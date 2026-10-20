#include "../common/types.h"

extern "C" u8* D_0034e948;

void func_00198970(u8* object) {
    if ((*(u32*)(object + 0x10c) & 0x800) != 0) {
        u32** target = *(u32***)(D_0034e948 + 0xb44);
        ((void (*)(u32**))(*target)[6])(target);
        *(s32*)(object + 0x488) = *(s32*)(object + 0x488) - 1;
        *(u32*)(object + 0x10c) = *(u32*)(object + 0x10c) & 0xfffff7ff;
    }
}
