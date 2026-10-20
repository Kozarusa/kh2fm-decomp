#include "../common/types.h"

u32 func_001c18d0(u8* object) {
    s64 ok = ((s64 (*)())*(u32*)(object + 0x10))();
    if (ok == 0) {
        return 0;
    }
    u8* data = *(u8**)(object + 0x20);
    if (data == 0) {
        return 1;
    }
    s32 kind = *(s32*)(*(u8**)(object + 0x1c) + 4);
    u8 value;
    if (kind == 0) {
        value = data[0xf];
    } else if (kind == 1) {
        value = data[0xd];
    } else {
        value = 0;
    }
    object[0x17] = value;
    return 1;
}